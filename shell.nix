{ pkgs ? import <nixpkgs> {} }:
with pkgs; mkShell rec {
  buildInputs = [
    cmake
    gpp
    clang-tools
  ];

  shellHook = ''
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${lib.makeLibraryPath (buildInputs) }
  '';
}
