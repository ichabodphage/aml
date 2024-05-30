{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
	selfpkgs = self.packages.${system}.default;
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
	    glew
	    glm
	    glfw
	    freeglut
	    clang
	    cmake
	    gnumake
          ];
          shellHook = ''
          '';
        };
	packages.default = pkgs.stdenv.mkDerivation {
	  name = "aml-tests";
	  src = ./.;
	  nativeBuildInputs = with pkgs; [
	    glew
	    glm
	    glfw
	    freeglut
	    clang
	    cmake
	    gnumake
	  ];
	  installPhase = ''
	  mkdir -p $out/bin
	  cd ..
	  cp test/3dTest $out/bin/3dTest
	  cp test/TextureTest $out/bin/TextureTest
	  chmod +x $out
	  '';
	};
	apps._3dTest = {
	  type = "app";
	  program = "${selfpkgs}/bin/3dTest";
	};
	apps.TextureTest = {
	  type = "app";
	  program = "${selfpkgs}/bin/TextureTest";
	};
      }
    );
}
