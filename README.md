# Development of Tasks
This is my submission for the CIBC Developer tasks for the software developer position at the Scientific Computing and Imaging Institute at the University of Utah.

All code was written by Matthew Walker. C++ code was written and compiled in Visual Studio Community 2015. Python code was written in Sublime Text 3 and run using python 3.6.2. All code was run on a Toshiba Satellite laptop running Windows 10.

## Required Task 2
Required task 2 was to create a CircularArray data structure in C++. The files for this task (mainly CircularArray.h and CIBC_Task1.cpp) can be found in the "CIBC_RequiredTask2" folder.
The CircularArray structure has several basic functions: A default constructor, add, and remove functions. The default constructor takes an integer as an argument. The integer denotes the size the CircularArray will be. The size of the array cannot be modified after it has been instantiated. Add will add an element to the array in the first available space. This space will be the space after the most recently placed element. If the array is full, then adding an element will override another element. Remove removes the oldest element in the array. This does not affect add. Removing an element does not gurantee that using add will use the recently vacated array position.
The CircularArray structure is generic, therefore it can be used to hold different element types. For example: 'CircularArray<int> cArray(5);' will create a CircularArray that can contain 5 integers. 'CircularArray<std::string> cArray(3)' creates a CircularArray that can contain 3 strings.
The main function in CIBC_Task1.cpp shows very basic uses of all the methods of the CircularArray data structure. This includes iterating through the array. Note that when iterating through the array, it will still count empty positions as containing uninitialized elements that are being stored.
To more extensively test the CircularArray, you could first attempt to store various different data types, (doubles, strings, integers, ect.), and make sure the elements are stored correctly. Additionally, you could test holding various number of elements. The next test would consist of removing elements from the list and checking that the array correctly updates the starting position of the array (the front iterator method could be used to check this). Tests would also need to determine if newly added elements override other elements when it reaches the "end" of the array. Methods to determine if the circular array is empty and the number of elements contained in the array were added to help flesh out the structure. Additionally, the CircularArray has an "at" method that takes an integer index to retrieve the element located at that specific index. Using this method, it is possible to retrieve elements and check that they exist in the array itself.
Required Task 2 can be run by loading up an IDE (such as Visual Studio) and adding the files located in "CIBC_RequiredTask2" folder to a project in visual studio. Then the project can be built and run.

## Required Task 3
Required task 3 was to create a python script that is given two images and evaluate the differences between them. For this task I decided that a decent way to give a quantitative analysis between two images would be to determine the differences between their RGB values. I took into consideration that not all images are the same dimensions, so I decided to have the program take quadrants of the images and calculate the average RGB values of each quadrant then compare Image 1 and Image 2's quadrant RGB values against each other.
The process is easier to visualize: given two images I split them into a grid of tiles. The table below is a basic conception of what happens when an image is split into tiles.

Tile 1 | Tile 2 | Tile 3
------ | ------ | ------
Tile 4 | Tile 5 | Tile 6
Tile 7 | Tile 8 | Tile 9

In each tile the average RGB value of all the pixels in the tile are computed. Then these values are compared to against the corresponding tile of the other image (tile 1 of image 1 is compared against tile 1 of image 2). The absolute value of the differences of the R G and B values for each tile comparison are added together and this constitutes the score for that tile comparison. The lower the score, the more similar the tiles were. A score of 0.0 denote that the tiles had the exact same average RGB values.
The program outputs two results: The first is the overall score for the image comparsion. This score is calculated by adding up the individual scores for the tile comparisons. This score works the same way as the individual scores, the lower it is the more similar the images are. The second thing that is displayed is a makeshift grid that will show the individual scores for the tile comparisons of the two images. If you had a 9 tiles then the program would display 9 numbers that are displayed in relation to where they are on the grid. For example, the bottom left number would be tile 7. This gives a more granular idea of how different certain parts of the images are from one another.
In order to run the script, I had the environment setup so that the script was in a folder that contained a folder of images (the given diff_test). The program was run from the directory the script resided in.
'python ./imageCompare.py diff_test/test_image_1.png diff_test/test_image_2.png 3'
The code above uses python to run the script (imageCompare.py) while inside the same directory as thes script. The script has three parameters that must be included. The first two are the relative paths (relative to the working directory) to image 1 and image 2. The third parameter is the square root of the number of tiles to split the images into. So with 3, it would create and compare 9 tiles. The program accepts values from 1 to 10 (inclusive) and they must be whole numbers. Note that the higher the number the larger the potential score for the comparisons will be. That is because the program is comparing more tiles per image so the differences between their RGB values start to add up. However, if the images are the same, the score will be 0.0.
The program also comes with some tests that can be run using pytest.
'pytest ./imageCompare.py' will run all tests included with the script.