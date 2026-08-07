{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let 
    forAllSystems = f:
      nixpkgs.lib.genAttrs nixpkgs.lib.platforms.unix (system:
        f {
          pkgs = import nixpkgs {inherit system;};
        });
  in {
    packages = forAllSystems ({pkgs, ...}: rec {
      default = pkgs.stdenv.mkDerivation {
        pname = "libfprint-goodixtls-55x4";
        version = "r1802-6e4fdc0";
        outputs = [
          "out"
          "devdoc"
        ];

        src = ./.;

        postPatch = ''
          patchShebangs \
            tests/test-runner.sh \
            tests/unittest_inspector.py \
            tests/virtual-image.py \
            tests/umockdev-test.py \
            tests/test-generated-hwdb.sh
          mkdir -p $out/include/libfprint-2
          cp -r libfprint/sigfm $out/include/libfprint-2
        '';

        nativeBuildInputs = with pkgs; [
          pkg-config
          meson
          ninja
          cmake
          gtk-doc
          gdb
          docbook-xsl-nons
          gobject-introspection
        ];

        buildInputs = with pkgs; [
          gusb
          glib
          cairo
          openssl
          opencv
          doctest
          libgudev
        ];

        mesonFlags = [
          "-Dudev_rules_dir=${placeholder "out"}/lib/udev/rules.d"
          # Include virtual drivers for fprintd tests
          "-Ddrivers=default"
          "-Dudev_hwdb_dir=${placeholder "out"}/lib/udev/hwdb.d"
        ];

        doCheck = false;

        meta = {
          description = "Fork of libfprint for Goodix TLS 55x4 devices support";
          homepage = "https://github.com/TheWeirdDev/libfprint";
          license = pkgs.lib.licenses.lgpl21Only;
          platforms = pkgs.lib.platforms.linux;
        };
      };
      fprintd = pkgs.fprintd.override {
        libfprint = default;
      };
    });
  };
}
