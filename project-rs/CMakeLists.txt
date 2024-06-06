include(FetchContent)

FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
# Set any global configuration variables such as `Rust_TOOLCHAIN` before this
#   line!
FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml CRATE_TYPES staticlib)

get_filename_component(_RUST_LIB_BINDINGS_DIR
                       "${CMAKE_CURRENT_LIST_DIR}/bindings/"
                       ABSOLUTE)
set(RUST_LIB_BINDINGS_DIR ${_RUST_LIB_BINDINGS_DIR} PARENT_SCOPE)
