from PIL import Image
import os,sys
import numpy as np

#Defining range that has <= as an end condition
#as opposed to range's default < end condition
def img_range(start, end, step):
    while start <= end:
        yield start
        start += step

#takes two arrays of average rgb values and compares them
#assumes that img1Rgbs and img2Rgbs are of the same length
#Returns score corresponding to total difference between images
#Returns array of individual difference scores between image tiles
#The larger the score, the bigger the difference between two images
#A result of 0 means the images are the same or very, very, similar
def rgbCompare(img1Rgbs, img2Rgbs):
	comparedArr = [None] * len(img1Rgbs)
	comparedSum = 0
	for i in range(len(img1Rgbs)):
		compareR = np.absolute(img1Rgbs[i][0] - img2Rgbs[i][0])
		compareG = np.absolute(img1Rgbs[i][1] - img2Rgbs[i][1])
		compareB = np.absolute(img1Rgbs[i][2] - img2Rgbs[i][2])
		compared = (compareR + compareG + compareB)
		comparedArr[i] = compared
		comparedSum += compared
	return comparedSum, comparedArr

def main(argv):
	if len(sys.argv) != 4:
		print("Incorrect number of arguments.")
		print("Please provide two image file locations, and the split modifier:")
		sys.exit()
	else:
		if int(sys.argv[3]) < 1 or int(sys.argv[3]) > 10:
			print("Error: Invalid split modifier.")
			print("Please choose a number between 1 and 10 (inclusive);")
			sys.exit()

	#Get the absolute path to both images
	script_dir = os.path.dirname(os.path.realpath(sys.argv[0]))
	cwd = os.getcwd()
	relative1 =  sys.argv[1]
	relative2 = sys.argv[2]
	abs_PathImg1 = os.path.join(cwd, relative1)
	abs_PathImg2 = os.path.join(cwd, relative2)
	print('Comparing {0} vs. {1}' .format(sys.argv[1], sys.argv[2]))
	rawImage1 = Image.open(abs_PathImg1)
	rawImage2 = Image.open(abs_PathImg2)
	image1 = rawImage1.convert('RGB')
	image2 = rawImage2.convert('RGB')

	width1, length1 = image1.size
	width2, length2 = image2.size

#rows = 5
#columns = 5
	rows = int(sys.argv[3])
	columns = int(sys.argv[3])

#bWidth is the width of individual tiles the image will be split into
	bWidth1 = int(width1/columns)
	bWidth2 = int(width2/columns)
#bLength is the length of individual tiles the image will be split into
	bLength1 = int(length1/rows)
	bLength2 = int(length2/rows)
#These arrays will hold the respective
	rgbArr1 = [None] * (rows*columns)
	rgbArr2 = [None] * (rows*columns)
	count = 0;

#split the image into a set of tiles and get the average rgb values of each tile
#image1 split and acquisition of rgb values
	for i in img_range(0, length1 - bLength1, bLength1):
		for j in img_range(0, width1 - bWidth1, bWidth1):
			box = (j, i, j+bWidth1, i+bLength1)
			tile = image1.crop(box)
			arr = np.array(tile)
			#print('i: {0} , j: {1}' .format(i, j))
			rgbArr1[count] = np.mean(arr, axis=(0,1))
			count += 1

	count = 0
#print(rgbArr1)
#image2 split and acquisition of rgb values
	for i in img_range(0, length2 - bLength2, bLength2):
		for j in img_range(0, width2 - bWidth2, bWidth2):
			box = (j, i, j+bWidth2, i+bLength2)
			tile = image2.crop(box)
			arr = np.array(tile)
			#print('i: {0} , j: {1}' .format(i, j))
			rgbArr2[count] = np.mean(arr, axis=(0,1))
			count += 1

#print(rgbArr2)
	result, compareArr = rgbCompare(rgbArr1, rgbArr2)

	print('Results (The closer the total image comparison score is to 0, the less diffrerences between images: ')
	print()
	print('Total Image comparsion score = {}'.format(result))
	gridCounter = 0
	for i in range(columns):
		for j in range(rows):
			print('{score: <24} '.format(score=compareArr[gridCounter]), end="")
			gridCounter += 1;
		print("")
	return result;

if __name__ == "__main__":
    main(sys.argv)

def test_main_same():
	sys.argv = [sys.argv[0], "diff_test/test_image_1.png", "diff_test/test_image_1.png", "3"]
	res = main(sys.argv)
	assert res == 0.0

def test_main_diff():
	sys.argv = [sys.argv[0], "diff_test/test_image_1.png", "diff_test/test_image_2.png", "3"]
	res = main(sys.argv)
	assert res != 0.0

def test_main_consistent():
	sys.argv = [sys.argv[0], "diff_test/test_image_1.png", "diff_test/test_image_2.png", "3"]
	res1 = main(sys.argv)
	sys.argv = [sys.argv[0], "diff_test/test_image_2.png", "diff_test/test_image_1.png", "3"]
	res2 = main(sys.argv)
	assert res1 == res2

def test_rgbCompare():
	list1_1 = [2.0, 3.0, 4.0]
	list1_2 = [5.0, 10.0, 7.0]
	list1_3 = [18.0, 90.0, 34.0]
	list1_4 = [55.0, 19.0, 42.0]
	list2_1 = [27.0, 88.0, 14.0]
	list2_2 = [90.0, 1.0, 0.0]
	list2_3 = [62.0, 9.0, 12.0]
	list2_4 = [11.0, 73.0, 21.0]

	result1 = 25.0 + 85.0 + 10.0
	result2 = 85.0 + 9.0 + 7.0
	result3 = 44.0 + 81.0 + 22.0
	result4 = 44.0 + 54.0 + 21.0
	totalResult = [result1, result2, result3, result4]

	test1=[list1_1, list1_2, list1_3, list1_4]
	test2=[list2_1, list2_2, list2_3, list2_4]
	sumTests, testArr = rgbCompare(test1, test2)
	assert sumTests == 487.0
	assert len(testArr) == len(totalResult)
	for i in range(len(testArr)):
		assert testArr[i] == totalResult[i]
		assert testArr[i] == totalResult[i]
		assert testArr[i] == totalResult[i]
