$ErrorActionPreference = "Stop"

# Project directories
$root = Split-Path -Parent $PSScriptRoot
$main = Join-Path $root "main.cpp"

$sfmlRoot = Join-Path $root "lib\SFML-2.6.2"
$sfmlInclude = Join-Path $sfmlRoot "include"
$sfmlLib = Join-Path $sfmlRoot "lib"

$buildDir = Join-Path $root "build"
$output = Join-Path $buildDir "candy_crush.exe"

# Check required files and folders
if (!(Test-Path $main)) {
    throw "main.cpp was not found in the project root."
}

if (!(Test-Path $sfmlInclude)) {
    throw "SFML include folder was not found."
}

if (!(Test-Path $sfmlLib)) {
    throw "SFML library folder was not found."
}

# Check GCC installation
$compiler = Get-Command g++ -ErrorAction SilentlyContinue

if (!$compiler) {
    throw "g++ was not found. Install MinGW GCC and add it to PATH."
}

# Create build directory
New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

# Excluded directories
$excludedDirs = @(
    $buildDir,
    (Join-Path $root "lib"),
    (Join-Path $root ".git")
) | ForEach-Object {
    [System.IO.Path]::GetFullPath($_).TrimEnd('\') + '\'
}

# Find all CPP files recursively
$otherSources = Get-ChildItem -Path $root -Recurse -File -Filter "*.cpp" |
    Where-Object {
        $fullPath = [System.IO.Path]::GetFullPath($_.FullName)

        $fullPath -ne [System.IO.Path]::GetFullPath($main) -and
        !($excludedDirs | Where-Object {
            $fullPath.StartsWith(
                $_,
                [System.StringComparison]::OrdinalIgnoreCase
            )
        })
    } |
    Sort-Object FullName |
    ForEach-Object {
        $_.FullName
    }

# Include main exactly once
$sourceFiles = @($main) + @($otherSources)

# Display source files
Write-Host ""
Write-Host "Building Candy Crush..." -ForegroundColor Cyan
Write-Host "Files being compiled:" -ForegroundColor Yellow

foreach ($file in $sourceFiles) {
    Write-Host $file
}

Write-Host ""
Write-Host "Total source files: $($sourceFiles.Count)"

# Compiler arguments
$arguments = @(
    "-std=c++17"
    "-g"
    "-I$root"
    "-I$sfmlInclude"
) + $sourceFiles + @(
    "-L$sfmlLib"
    "-o"
    $output
    "-lsfml-graphics"
    "-lsfml-window"
    "-lsfml-system"
)

# Compile and link
& $compiler.Source @arguments

if ($LASTEXITCODE -ne 0) {
    throw "Build failed. Check compiler errors above."
}

Write-Host ""
Write-Host "Build successful!" -ForegroundColor Green
Write-Host "Executable: $output" -ForegroundColor Green
