// ==============================================================
// Date: 2026-04-30 17:15:32 GMT
// Generated using vProto(2026.04.30)        https://www.cgen.dev
// Author: Sergey Shchekoldin        Email: shchekoldin@gmail.com
// ==============================================================

// Example usage:
// let mut m = crate::JsonRust::JsonRust::<JsonRust::JsonRustExample>::new();
// m.parse(&byte_slice);
// Also, you can redefine JsonRustTrait implementation for interacting with the JsonRust module.


#[cfg(target_arch = "x86_64")]
use std::arch::x86_64::*;

#[derive(Debug, PartialEq, Eq, Copy, Clone)]
#[allow(dead_code)]
enum NodeT {
    Loop1_0, // line_1
        Range1_0,
        Range2_0, Func2_1, Notify2_2,
        Range3_0, Func3_1, Notify3_2,
        Text4_0, Vector4_1, Text4_2, Range4_3, Cases4_4,
            Text5_0, Range5_1, Cases5_2,
                Text6_0, Vector6_1, Text6_2, Notify6_3,
                Vector7_0, Notify7_1,
                Range8_0, Func8_1, Notify8_2,
            Text9_0, Func9_1, Notify9_2,
            Range10_0, Func10_1, Notify10_2, Cases10_3,
                Func11_0, Notify11_1,
        Vector12_0, Notify12_1,
    Loop14_0, // line_14
        Uint14_0,
    Loop16_0, // line_16
    NoState
}
impl std::fmt::Display for NodeT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:?}", self)
    }
}

#[derive(Debug, Copy, Clone)]
pub struct StateT {
    pos: usize,
    consumed: usize,
    node: NodeT
}
impl StateT {
    pub fn new() -> Self { Self{ pos: 0, consumed: 0, node: NodeT::Loop1_0 } }
}
impl std::fmt::Display for StateT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} pos:{} consumed:{}", self.node, self.pos, self.consumed)
    }
}

#[allow(unreachable_code)]
pub trait JsonRustTrait {
    fn new() -> Self;

    // field accessors:
    fn depth(&mut self) -> &mut u32;
    fn key(&mut self) -> &mut Vec<u8>;
    fn value(&mut self) -> &mut Vec<u8>;

    // callbacks to be implemented by the user:
    fn gotKV(&mut self) { println!("Notify::gotKV"); }
    fn gotVal(&mut self) { println!("Notify::gotVal"); }
    fn popDepth(&mut self) { println!("Notify::popDepth"); }
    fn pushDepth(&mut self) { println!("Notify::pushDepth"); }

    // private functions:
    fn _func10_1(&mut self) -> bool {  *self.value() = std::mem::take(self.key());  return true; }
    fn _func11_0(&mut self) -> bool {  if *self.depth() == 0 { return false; } *self.depth() -= 1;  return true; }
    fn _func2_1(&mut self) -> bool {  *self.depth() += 1; self.key().clear();  return true; }
    fn _func3_1(&mut self) -> bool {  if *self.depth() == 0 { return false; } *self.depth() -= 1;  return true; }
    fn _func8_1(&mut self) -> bool {  *self.depth() += 1;  return true; }
    fn _func9_1(&mut self) -> bool {  *self.value() = std::mem::take(self.key());  return true; }
}

pub struct JsonRustExample
{
    key: Vec<u8>,
    value: Vec<u8>,
    depth: u32
}
#[allow(dead_code)]
impl JsonRustTrait for JsonRustExample {
    fn new() -> Self { Self{key: Vec::new(), value: Vec::new(), depth: 0} }
    fn depth(&mut self) -> &mut u32 { &mut self.depth }
    fn key(&mut self) -> &mut Vec<u8> { &mut self.key }
    fn value(&mut self) -> &mut Vec<u8> { &mut self.value }
}

pub struct JsonRust <T> {
    output: T,
    vstate: Vec<StateT>
}
#[allow(dead_code)]
#[allow(unused_variables)]
impl <T: JsonRustTrait> JsonRust<T> {
    pub fn new() -> Self { Self{ output: T::new(), vstate: vec![StateT::new()] } }
    pub fn empty(&self) -> bool { self.vstate.is_empty() }
    pub fn reset(&mut self) {
        *self.output.depth() = 0;
        *self.output.key() = Vec::new();
        *self.output.value() = Vec::new();
        for v in & mut self.vstate {
            v.node = NodeT::NoState;
        }
        self.vstate.push(StateT::new());
    }
    pub fn parse(&mut self, data : &[u8]) -> bool {
        for v in & mut self.vstate {
            v.pos = 0;
        }
        let mut reparse = true;
        while reparse {
            reparse = false;
            let mut d_flow = 0;
            let mut s_flow = 0;
            while s_flow < self.vstate.len() {
                if self.vstate[s_flow].node == NodeT::NoState {
                    s_flow += 1;
                } else if self.vstate[s_flow].pos == data.len() {
                    if s_flow != d_flow {
                        self.vstate[d_flow] = self.vstate[s_flow];
                    }
                    d_flow += 1;
                    s_flow += 1;
                } else {
                    reparse = true;
                    let mut state = self.vstate[s_flow];
                    self.parse_s(&mut state, data);
                    if state.node != NodeT::NoState {
                        self.vstate[d_flow] = state;
                        d_flow += 1;
                    }
                    s_flow += 1;
                }
            } // while
            if d_flow < self.vstate.len() {
                self.vstate.resize(d_flow, StateT::new());
            }
        }
        return !self.empty();
    }
    fn parse_s(&mut self, state: &mut StateT, data: &[u8]) {
        loop {
            if cfg!(debug_assertions) {
                println!("State: {} data: [{:#04X}, {:#04X}, {:#04X}, {:#04X}, {:#04X}]", state.node,
                    if state.pos+0 < data.len() { data[state.pos+0] } else { 0 },
                    if state.pos+1 < data.len() { data[state.pos+1] } else { 0 },
                    if state.pos+2 < data.len() { data[state.pos+2] } else { 0 },
                    if state.pos+3 < data.len() { data[state.pos+3] } else { 0 },
                    if state.pos+4 < data.len() { data[state.pos+4] } else { 0 });
            }
            let n = state.node;
            let d = state.pos;
            match state.node {
                NodeT::Loop1_0 => { self.loop1_0(state, data); }
                NodeT::Range1_0 => { self.range1_0(state, data); }
                NodeT::Range2_0 => { self.range2_0(state, data); }
                NodeT::Func2_1 => { self.func2_1(state, data); }
                NodeT::Notify2_2 => { self.notify2_2(state, data); }
                NodeT::Range3_0 => { self.range3_0(state, data); }
                NodeT::Func3_1 => { self.func3_1(state, data); }
                NodeT::Notify3_2 => { self.notify3_2(state, data); }
                NodeT::Text4_0 => { self.text4_0(state, data); }
                NodeT::Vector4_1 => { self.vector4_1(state, data); }
                NodeT::Text4_2 => { self.text4_2(state, data); }
                NodeT::Range4_3 => { self.range4_3(state, data); }
                NodeT::Cases4_4 => { self.cases4_4(state, data); }
                NodeT::Text5_0 => { self.text5_0(state, data); }
                NodeT::Range5_1 => { self.range5_1(state, data); }
                NodeT::Cases5_2 => { self.cases5_2(state, data); }
                NodeT::Text6_0 => { self.text6_0(state, data); }
                NodeT::Vector6_1 => { self.vector6_1(state, data); }
                NodeT::Text6_2 => { self.text6_2(state, data); }
                NodeT::Notify6_3 => { self.notify6_3(state, data); }
                NodeT::Vector7_0 => { self.vector7_0(state, data); }
                NodeT::Notify7_1 => { self.notify7_1(state, data); }
                NodeT::Range8_0 => { self.range8_0(state, data); }
                NodeT::Func8_1 => { self.func8_1(state, data); }
                NodeT::Notify8_2 => { self.notify8_2(state, data); }
                NodeT::Text9_0 => { self.text9_0(state, data); }
                NodeT::Func9_1 => { self.func9_1(state, data); }
                NodeT::Notify9_2 => { self.notify9_2(state, data); }
                NodeT::Range10_0 => { self.range10_0(state, data); }
                NodeT::Func10_1 => { self.func10_1(state, data); }
                NodeT::Notify10_2 => { self.notify10_2(state, data); }
                NodeT::Cases10_3 => { self.cases10_3(state, data); }
                NodeT::Func11_0 => { self.func11_0(state, data); }
                NodeT::Notify11_1 => { self.notify11_1(state, data); }
                NodeT::Vector12_0 => { self.vector12_0(state, data); }
                NodeT::Notify12_1 => { self.notify12_1(state, data); }
                NodeT::Loop14_0 => { self.loop14_0(state, data); }
                NodeT::Uint14_0 => { self.uint14_0(state, data); }
                NodeT::Loop16_0 => { self.loop16_0(state, data); }
                NodeT::NoState => { break; }
            }; // match
            if d == state.pos && n == state.node {
                break;
            }
        } // loop
    }
    fn loop1_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos == data.len() {
            return true;
        }
        if self.range1_0(state, data) { // case_1
            return true;
        }
        if self.range2_0(state, data) { // case_2
            return true;
        }
        if self.range3_0(state, data) { // case_3
            return true;
        }
        if self.text4_0(state, data) { // case_4
            return true;
        }
        if self.vector12_0(state, data) { // case_5
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn range1_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
            false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9-0xa][0xd][0x20][0x2c]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            let total = state.consumed + state.pos - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop1_0;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range1_0;
        return true;
    }
    fn range2_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x5b][0x7b]
        let datastart = state.pos;
        while state.pos < data.len() {
            if TERMINATOR[usize::from(data[state.pos])] {
                state.consumed += state.pos - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func2_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func2_1;
                state.consumed = 0;
                return ret;
            }
            state.pos += 1;
            state.node = NodeT::Func2_1;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range2_0;
        return true;
    }
    fn func2_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func2_1() {
            state.node = NodeT::Notify2_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify2_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.pushDepth();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn range3_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x5d][0x7d]
        let datastart = state.pos;
        while state.pos < data.len() {
            if TERMINATOR[usize::from(data[state.pos])] {
                state.consumed += state.pos - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func3_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func3_1;
                state.consumed = 0;
                return ret;
            }
            state.pos += 1;
            state.node = NodeT::Func3_1;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range3_0;
        return true;
    }
    fn func3_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func3_1() {
            state.node = NodeT::Notify3_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify3_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.popDepth();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn text4_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x22 != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Vector4_1;
                return true;
            }
        }
        state.node = NodeT::Text4_0;
        return true;
    }
    fn _vector4_1(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.key().clear();
        }
        let len = if (self.output.key().len() + data.len()) > 256 { 256 - self.output.key().len() } else { data.len() };
        self.output.key().extend_from_slice(&data[0 .. len]);
        state.consumed += data.len();
    }
    fn vector4_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.pos;
        let is_avx2 = is_x86_feature_detected!("avx2");
        let is_sse2 = is_x86_feature_detected!("sse2");
        while state.pos < data.len() {
            if is_avx2 && (state.pos + 32) <= data.len() {
                unsafe {
                    let d = _mm256_lddqu_si256(data.as_ptr().add(state.pos) as *const __m256i);
                    let m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
                    let r: u32 = _mm256_movemask_epi8(m) as u32;
                    if r > 0 {
                        state.pos += r.trailing_zeros() as usize;
                    } else {
                        state.pos += 32;
                        continue;
                    }
                }
            }
            else if is_sse2 && (state.pos + 16) <= data.len() {
                unsafe {
                    let d = _mm_loadu_si128(data.as_ptr().add(state.pos) as *const __m128i);
                    let m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
                    let r: u16 = _mm_movemask_epi8(m) as u16;
                    if r > 0 {
                        state.pos += r.trailing_zeros() as usize;
                    } else {
                        state.pos += 16;
                        continue;
                    }
                }
            }
            else if (state.pos + 8) <= data.len() {
                if data[state.pos] == 0x22 {
                    state.pos += 0;
                }
                else if data[state.pos + 1] == 0x22 {
                    state.pos += 1;
                }
                else if data[state.pos + 2] == 0x22 {
                    state.pos += 2;
                }
                else if data[state.pos + 3] == 0x22 {
                    state.pos += 3;
                }
                else if data[state.pos + 4] == 0x22 {
                    state.pos += 4;
                }
                else if data[state.pos + 5] == 0x22 {
                    state.pos += 5;
                }
                else if data[state.pos + 6] == 0x22 {
                    state.pos += 6;
                }
                else if data[state.pos + 7] == 0x22 {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(data[state.pos] == 0x22) {
                state.pos += 1;
                continue;
            }
            let pos = state.pos;
            self._vector4_1(state, &data[datastart .. pos]);
            state.consumed = 0;
            state.node = NodeT::Text4_2;
            return true;
        }
        if datastart < state.pos {
            let pos = state.pos;
            self._vector4_1(state, &data[datastart .. pos]);
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Vector4_1;
        return true;
    }
    fn text4_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x22 != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Range4_3;
                return true;
            }
        }
        state.node = NodeT::Text4_2;
        return true;
    }
    fn range4_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
            false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9-0xa][0xd][0x20]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Cases4_4;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range4_3;
        return true;
    }
    fn cases4_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos == data.len() {
            return true;
        }
        if self.text5_0(state, data) { // case_1
            return true;
        }
        if self.text9_0(state, data) { // case_2
            return true;
        }
        if self.range10_0(state, data) { // case_3
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn text5_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x3A != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Range5_1;
                return true;
            }
        }
        state.node = NodeT::Text5_0;
        return true;
    }
    fn range5_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
            false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x9-0xa][0xd][0x20]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Cases5_2;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range5_1;
        return true;
    }
    fn cases5_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos == data.len() {
            return true;
        }
        if self.text6_0(state, data) { // case_1
            return true;
        }
        if self.vector7_0(state, data) { // case_2
            return true;
        }
        if self.range8_0(state, data) { // case_3
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn text6_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x22 != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Vector6_1;
                return true;
            }
        }
        state.node = NodeT::Text6_0;
        return true;
    }
    fn _vector6_1(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().extend_from_slice(&data[0 .. len]);
        state.consumed += data.len();
    }
    fn vector6_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.pos;
        let is_avx2 = is_x86_feature_detected!("avx2");
        let is_sse2 = is_x86_feature_detected!("sse2");
        while state.pos < data.len() {
            if is_avx2 && (state.pos + 32) <= data.len() {
                unsafe {
                    let d = _mm256_lddqu_si256(data.as_ptr().add(state.pos) as *const __m256i);
                    let m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
                    let r: u32 = _mm256_movemask_epi8(m) as u32;
                    if r > 0 {
                        state.pos += r.trailing_zeros() as usize;
                    } else {
                        state.pos += 32;
                        continue;
                    }
                }
            }
            else if is_sse2 && (state.pos + 16) <= data.len() {
                unsafe {
                    let d = _mm_loadu_si128(data.as_ptr().add(state.pos) as *const __m128i);
                    let m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
                    let r: u16 = _mm_movemask_epi8(m) as u16;
                    if r > 0 {
                        state.pos += r.trailing_zeros() as usize;
                    } else {
                        state.pos += 16;
                        continue;
                    }
                }
            }
            else if (state.pos + 8) <= data.len() {
                if data[state.pos] == 0x22 {
                    state.pos += 0;
                }
                else if data[state.pos + 1] == 0x22 {
                    state.pos += 1;
                }
                else if data[state.pos + 2] == 0x22 {
                    state.pos += 2;
                }
                else if data[state.pos + 3] == 0x22 {
                    state.pos += 3;
                }
                else if data[state.pos + 4] == 0x22 {
                    state.pos += 4;
                }
                else if data[state.pos + 5] == 0x22 {
                    state.pos += 5;
                }
                else if data[state.pos + 6] == 0x22 {
                    state.pos += 6;
                }
                else if data[state.pos + 7] == 0x22 {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(data[state.pos] == 0x22) {
                state.pos += 1;
                continue;
            }
            let pos = state.pos;
            self._vector6_1(state, &data[datastart .. pos]);
            state.consumed = 0;
            state.node = NodeT::Text6_2;
            return true;
        }
        if datastart < state.pos {
            let pos = state.pos;
            self._vector6_1(state, &data[datastart .. pos]);
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Vector6_1;
        return true;
    }
    fn text6_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x22 != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Notify6_3;
                return true;
            }
        }
        state.node = NodeT::Text6_2;
        return true;
    }
    fn notify6_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotKV();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn _vector7_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().extend_from_slice(&data[0 .. len]);
        state.consumed += data.len();
    }
    fn vector7_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true, 
            false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
             true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
             true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x2d-0x2e][0-9][A-Z][a-z]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            let pos = state.pos;
            self._vector7_0(state, &data[datastart .. pos]);
            let total = state.consumed + state.pos - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Notify7_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.pos {
            let pos = state.pos;
            self._vector7_0(state, &data[datastart .. pos]);
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Vector7_0;
        return true;
    }
    fn notify7_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotKV();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn range8_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x5b][0x7b]
        let datastart = state.pos;
        while state.pos < data.len() {
            if TERMINATOR[usize::from(data[state.pos])] {
                state.consumed += state.pos - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func8_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func8_1;
                state.consumed = 0;
                return ret;
            }
            state.pos += 1;
            state.node = NodeT::Func8_1;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range8_0;
        return true;
    }
    fn func8_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func8_1() {
            state.node = NodeT::Notify8_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify8_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.pushDepth();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn text9_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.pos < data.len() {
            if 0x2C != data[state.pos] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.pos += 1;
                state.node = NodeT::Func9_1;
                return true;
            }
        }
        state.node = NodeT::Text9_0;
        return true;
    }
    fn func9_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func9_1() {
            state.node = NodeT::Notify9_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify9_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotVal();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn range10_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x5d][0x7d]
        let datastart = state.pos;
        while state.pos < data.len() {
            if TERMINATOR[usize::from(data[state.pos])] {
                state.consumed += state.pos - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func10_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func10_1;
                state.consumed = 0;
                return ret;
            }
            state.pos += 1;
            state.node = NodeT::Func10_1;
            return true;
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Range10_0;
        return true;
    }
    fn func10_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func10_1() {
            state.node = NodeT::Notify10_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify10_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotVal();
        state.node = NodeT::Cases10_3;
        return true;
    }
    fn cases10_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.func11_0(state, data);
    }
    fn func11_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if self.output._func11_0() {
            state.node = NodeT::Notify11_1;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify11_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.popDepth();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn _vector12_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().extend_from_slice(&data[0 .. len]);
        state.consumed += data.len();
    }
    fn vector12_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true, 
            false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
             true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true, false, 
             true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
            false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0x2d-0x2e][0-9][A-Z][_][a-z]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            let pos = state.pos;
            self._vector12_0(state, &data[datastart .. pos]);
            let total = state.consumed + state.pos - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Notify12_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.pos {
            let pos = state.pos;
            self._vector12_0(state, &data[datastart .. pos]);
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Vector12_0;
        return true;
    }
    fn notify12_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotVal();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn loop14_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.uint14_0(state, data);
    }
    fn _uint14_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            *self.output.depth() = 0;
        }
        for x in data {
            *self.output.depth() = *self.output.depth()*10 + u32::from(*x - b'0');
        }
    }
    fn uint14_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        static TERMINATOR:[bool;256] = [
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
            false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true]; // [0-9]
        let datastart = state.pos;
        while state.pos < data.len() {
            if (state.pos + 8) <= data.len() {
                if TERMINATOR[usize::from(data[state.pos])] {
                    state.pos += 0;
                }
                else if TERMINATOR[usize::from(data[state.pos + 1])] {
                    state.pos += 1;
                }
                else if TERMINATOR[usize::from(data[state.pos + 2])] {
                    state.pos += 2;
                }
                else if TERMINATOR[usize::from(data[state.pos + 3])] {
                    state.pos += 3;
                }
                else if TERMINATOR[usize::from(data[state.pos + 4])] {
                    state.pos += 4;
                }
                else if TERMINATOR[usize::from(data[state.pos + 5])] {
                    state.pos += 5;
                }
                else if TERMINATOR[usize::from(data[state.pos + 6])] {
                    state.pos += 6;
                }
                else if TERMINATOR[usize::from(data[state.pos + 7])] {
                    state.pos += 7;
                }
                else
                {
                    state.pos += 8;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.pos])]) {
                state.pos += 1;
                continue;
            }
            let pos = state.pos;
            self._uint14_0(state, &data[datastart .. pos]);
            let total = state.consumed + state.pos - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop14_0;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.pos {
            let pos = state.pos;
            self._uint14_0(state, &data[datastart .. pos]);
        }
        state.consumed += state.pos - datastart;
        state.node = NodeT::Uint14_0;
        return true;
    }
    fn loop16_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        state.node = NodeT::NoState;
        return true;
    }
} // impl
