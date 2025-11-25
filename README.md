# Image Preprocessing Library or Class in C++ & Python

## Description

This tool preprocesses images from a specified directory. It is designed to prepare image datasets for use in machine learning models, particularly for image classification tasks. The tool converts images to grayscale, resizes them, and extracts pixel data into text files.

## Features

-   Processes multiple subdirectories of images within a root folder.
-   Converts images to grayscale.
-   Resizes images to a fixed size (28x28 pixels).
-   Normalizes pixel values to a range of 0.0 to 1.0.
-   Outputs pixel data as comma-separated values (CSV) in text files.
-   User-friendly folder selection dialog (for Windows).

## Prerequisites

-   A C++ compiler that supports C++17 (for compiling the C++ code).
-   Windows Operating System (for the folder browser functionality).
-   Python 3.x.
-   Pillow (Python Imaging Library) installed. You can install it using pip:
    ```
    pip install Pillow
    ```

## How to Use

1.  **Compile the C++ code:**
    -   Open a terminal or command prompt with a C++ compiler (like g++ or MSVC) in your environment.
    -   Navigate to the `source` directory.
    -   Compile `main.cpp`:
        ```bash
        g++ main.cpp -o main.exe -lcomdlg32 -lole32 -lshell32 -std=c++17
        ```
        *(Note: The required libraries might vary based on your compiler setup.)*

2.  **Run the application:**
    -   From within the `source` directory, execute the compiled program:
        ```bash
        main.exe
        ```
    -   A dialog box will appear. Select the root folder containing your image dataset.
    -   **Important**: Ensure that `preprocess.py` is in the same directory as the `main.exe` executable.

## Input Data Structure

Your image data should be organized into subdirectories within a main folder. Each subdirectory should contain images belonging to a specific class. For example:

```
/path/to/your/dataset/
|-- class_1/
|   |-- image1.jpg
|   |-- image2.png
|   |-- ...
|-- class_2/
|   |-- image3.jpeg
|   |-- image4.bmp
|   |-- ...
```

The tool will process all images with valid extensions (`.jpg`, `.jpeg`, `.png`, `.bmp`, `.tif`, `.tiff`) found recursively within each class folder.

## Output

The tool generates a `pixels` directory inside the `source` directory. For each class subdirectory from the input, a corresponding `.txt` file is created in the `pixels` directory.

Each line in the output text file represents one image and contains 784 (28x28) comma-separated floating-point numbers, which are the normalized grayscale pixel values.

Example output structure:

```
source/
|-- pixels/
|   |-- class_1.txt
|   |-- class_2.txt
|-- main.cpp
|-- ...
```
