use std::fs;

#[allow(non_snake_case)]
mod jsonRust;

pub struct jsonResult2
{
    key: String,
    value: String,
    depth: u32
}

#[allow(dead_code)]
impl jsonRust::JsonRustResultTrait for jsonResult2 {
    fn new() -> Self { Self{key: String::new(), value: String::new(), depth: 0} }
    fn depth(&mut self) -> &mut u32 { &mut self.depth }
    fn key(&mut self) -> &mut String { &mut self.key }
    fn value(&mut self) -> &mut String { &mut self.value }
    fn gotKV(&mut self) { println!("gotKV({}): {}->{}", self.depth, self.key, self.value); }
    fn gotVal(&mut self) { println!("gotVal({}): {}", self.depth, self.value); }
    fn popDepth(&mut self) { println!("popDepth({})", self.depth); }
    fn pushDepth(&mut self) { println!("pushDepth({}): {}", self.depth, self.key); }
}


fn main() {
    let contents = fs::read_to_string("../input.txt").expect("Should have been able to read the file");

    let byte_slice: &[u8] = contents.as_bytes();
//    println!("contents: {contents}");

    let mut m = crate::jsonRust::JsonRust::<jsonResult2>::new();
    m.parse(&byte_slice);
    println!("-----flow-----");
    for i in 0..byte_slice.len() {
//println!("==========DATA: {:#04X}===========", byte_slice[i]);
        m.parse(&byte_slice[i..i+1]);
    }
}

