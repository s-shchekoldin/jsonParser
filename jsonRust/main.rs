use std::fs;

#[allow(non_snake_case)]
mod JsonRust;

pub struct JsonResult2
{
    key: Vec<u8>,
    value: Vec<u8>,
    depth: u32
}

#[allow(dead_code)]
impl JsonRust::JsonRustTrait for JsonResult2 {
    fn new() -> Self { Self{key: Vec::new(), value: Vec::new(), depth: 0} }
    fn depth(&mut self) -> &mut u32 { &mut self.depth }
    fn key(&mut self) -> &mut Vec<u8> { &mut self.key }
    fn value(&mut self) -> &mut Vec<u8> { &mut self.value }
    fn gotKV(&mut self) { println!("gotKV({}): {}->{}", self.depth, String::from_utf8(self.key.clone()).unwrap(), String::from_utf8(self.value.clone()).unwrap());  }
    fn gotVal(&mut self) { println!("gotVal({}): {}", self.depth, String::from_utf8(self.value.clone()).unwrap()); }
    fn popDepth(&mut self) { println!("popDepth({})", self.depth); }
    fn pushDepth(&mut self) { println!("pushDepth({}): {}", self.depth, String::from_utf8(self.key.clone()).unwrap()); }
}

fn main() {
    let contents = fs::read_to_string("../input.txt").expect("Should have been able to read the file");

    let byte_slice: &[u8] = contents.as_bytes();
//    println!("contents: {contents}");

    let mut m = crate::JsonRust::JsonRust::<JsonResult2>::new();
    m.parse(&byte_slice);
    println!("-----flow-----");
    for i in 0..byte_slice.len() {
//println!("==========DATA: {:#04X}===========", byte_slice[i]);
        m.parse(&byte_slice[i..i+1]);
    }
}

