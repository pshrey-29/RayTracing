Language: C++  
GUI Library: ImGui  

Implemented Features:  
Camera System:  
-Ability to move the camera position, orientation and field of view.  
-Support for orthographic and perspective projection.  
-Camera rays generated based on the projection type and view matrix.  

Object Support:  
-Support for multiple objects in the scene.  
-Signed Distance Function (SDF) used for defining the geometry of objects.  
-No support for polygonal meshes yet.  

Material Properties:  
-Roughness of materials implemented.  
-Reflection of materials implemented.  

<img width="492" alt="09_accumulated data 1" src="https://user-images.githubusercontent.com/83825007/225366076-e97cefc9-c74c-434c-ba8b-58671bb43aa0.png">
<img width="492" alt="09_accumulated data 2" src="https://user-images.githubusercontent.com/83825007/225366095-dc4aa26b-4b09-4888-8095-6946a62f0370.png">
<img width="492" alt="09_accumulated data 3" src="https://user-images.githubusercontent.com/83825007/225366108-fcdda3e7-f2eb-45ac-b0bb-0f77f14e3c27.png">

*Upcoming Features:  
Multithreading:   
-Implementing multithreading to speed up the rendering process.  
-Divide the image into tiles and assign each tile to a separate thread.  

Additional Material Properties:  
-Implementing additional material properties like transparency, refraction and emissivity.  

Optimizations:  
-Implementing optimizations to speed up the raytracing process.  
-BVH (Bounding Volume Hierarchy) to accelerate ray-object intersection tests.  

Polygonal Mesh Support:  
-Implementing support for polygonal meshes.  
-Loading polygonal mesh data from file formats like OBJ or FBX.  

Additional Lighting Techniques:  
-Implementing additional lighting techniques like ambient occlusion and indirect lighting.  
