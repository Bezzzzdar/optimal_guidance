param (
    [string]$argv
)

if ($argv -eq "--install")
{
    New-Item -ItemType Directory -Force -Path "plots"
    .\out\build\x64-debug\optimal_guidance.exe
    gnuplot.exe .\values\plot.gnu
}
elseif ($argv -eq "--clean")
{
    Remove-Item -Recurse -Force -Path "plots"
} 

exit 0