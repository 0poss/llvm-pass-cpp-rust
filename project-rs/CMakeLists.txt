find_package(Corrosion REQUIRED)

corrosion_import_crate(MANIFEST_PATH Cargo.toml CRATE_TYPES staticlib)

get_filename_component(_RUST_LIB_BINDINGS_DIR
                       "${CMAKE_CURRENT_LIST_DIR}/bindings/"
                       ABSOLUTE)
set(RUST_LIB_BINDINGS_DIR ${_RUST_LIB_BINDINGS_DIR} PARENT_SCOPE)
