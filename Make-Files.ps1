function BuildDirectory {
    param (
        [String]$DirectoryName
    )
    
    mkdir $DirectoryName
    #C++
    mkdir -Path ".\$DirectoryName\C++"
    build_cpp_makefile $DirectoryName
    build_cpp_main $DirectoryName
    #RUST
    mkdir -Path ".\$DirectoryName\Rust"

}

function build_cpp_makefile{
    param (
        [String]$DirectoryName
    )
    echo ".SILENT:
    
    build:
    g++ $DirectoryName.cpp -o $DirectoryName.exe
    .\$DirectoryName.exe" >> ".\$DirectoryName\C++\Makefile"
}

function build_cpp_main{
    param (
        [String]$DirectoryName
    )
    echo '#include <cstdio>

int main(){
    printf("%s", "hello world");
    return 0;
}' >> ".\$DirectoryName\C++\$DirectoryName.cpp"
}

if ($args.Count -eq 0) {
    Write-Host "Not enough arguments."
}
elseif( $args.Count -eq 1){
    BuildDirectory($args[0])
}