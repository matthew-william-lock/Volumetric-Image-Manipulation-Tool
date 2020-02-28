# A Volumetric Image Manipulation Tool
This progam is used to extract MRI images from a set of raw files and perform image manipulation on the extracted images.
Functionality includes:
- Image extraction
- Difference imaging
- Slice extraction

**Step 1:** Compile VolImage
```
cd src
make
```

**Step 2:** Run VolImage
```
cd src
volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]
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