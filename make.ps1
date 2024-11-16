param (
    [string]$argv
)

function install {
    cmake.exe .\CMakeLists.txt
    cmake --build .
    .\Debug\optimal_guidance.exe
    New-Item -ItemType Directory -Force -Path "plots" > $null 2>&1
    gnuplot.exe .\values\plot.gnu
}
function clean {
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
    Remove-Item ".\values\*.csv"
}

function replot {
    Remove-Item ".\plots\*.png"
    gnuplot.exe .\values\plot.gnu
}

if ($argv -eq "--install")
{
    install
}
elseif ($argv -eq "--clean")
{
    clean
} 
elseif ($argv -eq "--rebuild") 
{
    clean
    install
}
elseif ($argv -eq "--replot") 
{
    replot
}

exit 0