# A Volumetric Image Manipulation Tool
This progam is used to extract MRI images from a set of raw files and perform image manipulation on the extracted images.
Functionality includes:
- Image extraction
- Difference imaging
- Slice extraction

## Source files
**driver.cpp:** : Used to implement functionality in volimage
**volimage.h**: Defines the volimage class
**volimage.cpp**: Implements the volimage class

## Installation
**Step 1:** Compile VolImage
```
cd src
make
```

**Step 2:** Run VolImage
```
cd src
./volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]
```

# Usage
Only one operation can be performed for each instance of VolImage

Required arguments 
```
imageBase           prefix for the file sequence
```

Optional arguments:
| Parameter                 | Description   |	
| :------------------------ | :-------------|
| -d i j output_file_name | difference imaging mage on images i and j where output_file_name = i-j
| -x i output_file_name | image extraction of image i in set to output_file_name
| -g i output_file_name | slice extraction of row i from all the images in the set to output_file_name

Note: All output images are written to bin file