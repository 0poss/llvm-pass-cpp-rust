use std::fs;
use std::path::Path;

fn main() {
    let bindings_dir = Path::new("bindings");

    fs::create_dir_all(bindings_dir).expect("Unable to create bindings directory");

    cbindgen::generate(".")
        .expect("Unable to generate bindings")
        .write_to_file(bindings_dir.join("project-rs.hpp"));
}
