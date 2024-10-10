param (
    [string]$argv
)

if ($argv -eq "--install")
{
    cmake.exe .\CMakeLists.txt
    cmake --build .
    New-Item -ItemType Directory -Force -Path "plots"
    .\Debug\optimal_guidance.exe
    gnuplot.exe .\values\plot.gnu
}
elseif ($argv -eq "--clean")
{
    Remove-Item -Recurse -Force -Path "plots"
    Remove-Item -Recurse -Force -Path "CMakeFiles"
    Remove-Item -Recurse -Force -Path "Debug"
    Remove-Item -Recurse -Force -Path "optimal_guidance.dir"
    Remove-Item -Recurse -Force -Path "x64"
    Remove-Item "CMakeCache.txt"
    Remove-Item "cmake_install.cmake"
    Remove-Item "*.vcxproj"
    Remove-Item "*.vcxproj.filters"
    Remove-Item "*.sln"
    Remove-Item ".\values\target_values.csv"
} 

exit 0