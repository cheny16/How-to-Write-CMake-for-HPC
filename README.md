# How to Write CMake for HPC ![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

CMake is a powerful configuration tool :wrench: for C/C++/etc.. In HPC programs, CMake is also highly recommended, because there would be a lots of different kinds of HPC frameworks to be used, by using CMake it will be very easy to detect the required HPC environments automatically and so that the correct compilations can be done. 

This repository contains some notes :page_with_curl: and examples on how to write `CMakeLists.txt` files for HPC programs with different HPC environments. These notes & examples are divided into different corresponding subfolders. :open_file_folder:

## Contents
<table>
  <thead>
    <tr>
      <th> Type </th>
      <th> Framework </th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="4"> CPU </td>
    </tr>
    <tr>
      <td> <a href="https://github.com/cheny16/How-to-Write-CMake-for-HPC/blob/main/MPI">MPI</a> </td>
    </tr>
      <td> <a href="https://github.com/cheny16/How-to-Write-CMake-for-HPC/tree/main/OpenMP">OpenMP</a> </td>
    <tr>
      <td> Vectorization </td>
    </tr>
  </tbody>
  
  <tbody>
    <tr>
      <td rowspan="5"> GPU </td>
    </tr>
    <tr>
      <td> CUDA </td>
    </tr>
      <td> HIP </td>
    <tr>
      <td> <a href="https://github.com/cheny16/How-to-Write-CMake-for-HPC/tree/main/OpenACC">OpenACC</a> </td>
    </tr>
    <tr>
      <td> ... </td>
    </tr>
  </tbody>
</table>
