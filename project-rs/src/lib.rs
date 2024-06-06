extern "C" {
    fn hello_from_cpp();
}

#[no_mangle]
pub extern "C" fn hello_from_rust() {
    println!("hello, world! -- from a Rust function!");
    unsafe { hello_from_cpp() };
}
