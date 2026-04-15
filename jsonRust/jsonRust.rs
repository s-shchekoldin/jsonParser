// ==============================================================
// Date: 2026-04-15 19:12:27 GMT
// Generated using vProto(2026.04.15)        https://www.cgen.dev
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

// Example usage:
// let mut m = crate::JsonRust::JsonRust::<JsonRust::JsonRustExample>::new();
// m.parse(&byte_slice);
// If necessary, override JsonRust::JsonRustExample and its trait as well


#[derive(Debug, PartialEq, Eq, Copy, Clone)]
#[allow(dead_code)]
enum NodeT {
    Loop1_0, // line_1
        Range1_0,
        Range2_0, Func2_1, Func2_2, Notify2_3,
        Range3_0, Func3_1, Notify3_2,
        Text4_0, String4_1, Text4_2, Range4_3, Cases4_4,
            Text5_0, Range5_1, Cases5_2,
                Text6_0, String6_1, Text6_2, Notify6_3,
                String7_0, Notify7_1,
                Range8_0, Func8_1, Notify8_2,
            Text9_0, Func9_1, Notify9_2,
            Range10_0, Func10_1, Notify10_2, Func10_3, Notify10_4,
        String11_0, Notify11_1,
    Loop13_0, // line_13
        Uint13_0,
    Loop15_0, // line_15
    NoState
}
impl std::fmt::Display for NodeT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:?}", self)
    }
}

#[derive(Debug, Copy, Clone)]
pub struct StateT {
    node: NodeT,
    left: usize,
    right: usize,
    consumed: usize
}
impl StateT {
    pub fn new() -> Self { Self{ node: NodeT::Loop1_0, left: 0, right: 0, consumed: 0 } }
    pub fn remain(&self) -> usize { self.right - self.left }
}
impl std::fmt::Display for StateT {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} remain:{}({}->{}) consumed:{}", self.node, self.remain(), self.left, self.right, self.consumed)
    }
}

pub trait JsonRustTrait {
    fn new() -> Self;
    // field accessors:
    fn depth(&mut self) -> &mut u32;
    fn key(&mut self) -> &mut String;
    fn value(&mut self) -> &mut String;
    // callbacks to be implemented by the user:
    fn gotKV(&mut self);
    fn gotVal(&mut self);
    fn popDepth(&mut self);
    fn pushDepth(&mut self);
}

pub struct JsonRustExample
{
    key: String,
    value: String,
    depth: u32
}
#[allow(dead_code)]
impl JsonRustTrait for JsonRustExample {
    fn new() -> Self { Self{key: String::new(), value: String::new(), depth: 0} }
    fn depth(&mut self) -> &mut u32 { &mut self.depth }
    fn key(&mut self) -> &mut String { &mut self.key }
    fn value(&mut self) -> &mut String { &mut self.value }
    fn gotKV(&mut self) { println!("Notify::gotKV"); }
    fn gotVal(&mut self) { println!("Notify::gotVal"); }
    fn popDepth(&mut self) { println!("Notify::popDepth"); }
    fn pushDepth(&mut self) { println!("Notify::pushDepth"); }
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
        *self.output.key()= String::new();
        *self.output.value()= String::new();
        for v in & mut self.vstate {
            v.node = NodeT::NoState;
        }
        self.vstate.push(StateT::new());
    }
    pub fn parse(&mut self, data : &[u8]) -> bool {
        for v in & mut self.vstate {
            v.left = 0;
            v.right = data.len();
        }
        let mut reparse = true;
        while reparse {
            reparse = false;
            let mut d_flow = 0;
            let mut s_flow = 0;
            while s_flow < self.vstate.len() {
                if self.vstate[s_flow].node == NodeT::NoState {
                    s_flow += 1;
                } else if self.vstate[s_flow].remain() == 0 {
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
                    if state.remain() > 0 { data[state.left+0] } else { 0 },
                    if state.remain() > 1 { data[state.left+1] } else { 0 },
                    if state.remain() > 2 { data[state.left+2] } else { 0 },
                    if state.remain() > 3 { data[state.left+3] } else { 0 },
                    if state.remain() > 4 { data[state.left+4] } else { 0 });
            }
            let n = state.node;
            let d = state.left;
            match state.node {
                NodeT::Loop1_0 => { self.loop1_0(state, data); }
                NodeT::Range1_0 => { self.range1_0(state, data); }
                NodeT::Range2_0 => { self.range2_0(state, data); }
                NodeT::Func2_1 => { self.func2_1(state, data); }
                NodeT::Func2_2 => { self.func2_2(state, data); }
                NodeT::Notify2_3 => { self.notify2_3(state, data); }
                NodeT::Range3_0 => { self.range3_0(state, data); }
                NodeT::Func3_1 => { self.func3_1(state, data); }
                NodeT::Notify3_2 => { self.notify3_2(state, data); }
                NodeT::Text4_0 => { self.text4_0(state, data); }
                NodeT::String4_1 => { self.string4_1(state, data); }
                NodeT::Text4_2 => { self.text4_2(state, data); }
                NodeT::Range4_3 => { self.range4_3(state, data); }
                NodeT::Cases4_4 => { self.cases4_4(state, data); }
                NodeT::Text5_0 => { self.text5_0(state, data); }
                NodeT::Range5_1 => { self.range5_1(state, data); }
                NodeT::Cases5_2 => { self.cases5_2(state, data); }
                NodeT::Text6_0 => { self.text6_0(state, data); }
                NodeT::String6_1 => { self.string6_1(state, data); }
                NodeT::Text6_2 => { self.text6_2(state, data); }
                NodeT::Notify6_3 => { self.notify6_3(state, data); }
                NodeT::String7_0 => { self.string7_0(state, data); }
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
                NodeT::Func10_3 => { self.func10_3(state, data); }
                NodeT::Notify10_4 => { self.notify10_4(state, data); }
                NodeT::String11_0 => { self.string11_0(state, data); }
                NodeT::Notify11_1 => { self.notify11_1(state, data); }
                NodeT::Loop13_0 => { self.loop13_0(state, data); }
                NodeT::Uint13_0 => { self.uint13_0(state, data); }
                NodeT::Loop15_0 => { self.loop15_0(state, data); }
                NodeT::NoState => { break; }
            }; // match
            if d == state.left && n == state.node {
                break;
            }
        } // loop
    }
    fn loop1_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
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
        if self.string11_0(state, data) { // case_5
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop1_0;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        state.consumed += state.left - datastart;
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
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left + 0])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func2_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func2_1;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Func2_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range2_0;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func2_1(this : &mut T) -> bool {
         *this.depth() += 1; 
        return true;
    }
    fn func2_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func2_1(&mut self.output) {
            state.node = NodeT::Func2_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func2_2(this : &mut T) -> bool {
         *this.key() = String::new(); 
        return true;
    }
    fn func2_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func2_2(&mut self.output) {
            state.node = NodeT::Notify2_3;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify2_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
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
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left + 0])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func3_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func3_1;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Func3_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range3_0;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func3_1(this : &mut T) -> bool {
         *this.depth() -= 1; 
        return true;
    }
    fn func3_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func3_1(&mut self.output) {
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
        if state.left < state.right {
            if 0x22 != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::String4_1;
                return true;
            }
        }
        state.node = NodeT::Text4_0;
        return true;
    }
    fn _string4_1(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.key().clear();
        }
        let len = if (self.output.key().len() + data.len()) > 256 { 256 - self.output.key().len() } else { data.len() };
        self.output.key().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string4_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if data[state.left + 0] == 0x22 {
                    state.left += 0;
                }
                else if data[state.left + 1] == 0x22 {
                    state.left += 1;
                }
                else if data[state.left + 2] == 0x22 {
                    state.left += 2;
                }
                else if data[state.left + 3] == 0x22 {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(data[state.left + 0] == 0x22) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string4_1(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Text4_2;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string4_1(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String4_1;
        return true;
    }
    fn text4_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x22 != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Cases4_4;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range4_3;
        return true;
    }
    fn cases4_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
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
        if state.left < state.right {
            if 0x3A != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            state.consumed = 0;
            state.node = NodeT::Cases5_2;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range5_1;
        return true;
    }
    fn cases5_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left == state.right {
            return true;
        }
        if self.text6_0(state, data) { // case_1
            return true;
        }
        if self.string7_0(state, data) { // case_2
            return true;
        }
        if self.range8_0(state, data) { // case_3
            return true;
        }
        state.node = NodeT::NoState;
        return true;
    }
    fn text6_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x22 != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::String6_1;
                return true;
            }
        }
        state.node = NodeT::Text6_0;
        return true;
    }
    fn _string6_1(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string6_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if data[state.left + 0] == 0x22 {
                    state.left += 0;
                }
                else if data[state.left + 1] == 0x22 {
                    state.left += 1;
                }
                else if data[state.left + 2] == 0x22 {
                    state.left += 2;
                }
                else if data[state.left + 3] == 0x22 {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(data[state.left + 0] == 0x22) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string6_1(state, &data[datastart .. left]);
            state.consumed = 0;
            state.node = NodeT::Text6_2;
            return true;
        }
        if datastart < state.left {
            let left = state.left;
            self._string6_1(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String6_1;
        return true;
    }
    fn text6_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if state.left < state.right {
            if 0x22 != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
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
    fn _string7_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string7_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string7_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Notify7_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string7_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String7_0;
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
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left + 0])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func8_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func8_1;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Func8_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range8_0;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func8_1(this : &mut T) -> bool {
         *this.depth() += 1; 
        return true;
    }
    fn func8_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func8_1(&mut self.output) {
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
        if state.left < state.right {
            if 0x2C != data[state.left] {
                state.node = NodeT::NoState;
                return false;
            } else {
                state.left += 1;
                state.node = NodeT::Func9_1;
                return true;
            }
        }
        state.node = NodeT::Text9_0;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func9_1(this : &mut T) -> bool {
         *this.value() = this.key().clone(); 
        return true;
    }
    fn func9_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func9_1(&mut self.output) {
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
        let datastart = state.left;
        while state.left < state.right {
            if TERMINATOR[usize::from(data[state.left + 0])] {
                state.consumed += state.left - datastart;
                state.node = if state.consumed >= 1 { NodeT::Func10_1 } else { NodeT::NoState };
                let ret = state.node == NodeT::Func10_1;
                state.consumed = 0;
                return ret;
            }
            state.left += 1;
            state.node = NodeT::Func10_1;
            return true;
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Range10_0;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func10_1(this : &mut T) -> bool {
         *this.value() = this.key().clone(); 
        return true;
    }
    fn func10_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func10_1(&mut self.output) {
            state.node = NodeT::Notify10_2;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify10_2(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotVal();
        state.node = NodeT::Func10_3;
        return true;
    }
    #[allow(unused_variables)]
    #[allow(unreachable_code)]
    fn _func10_3(this : &mut T) -> bool {
         *this.depth() -= 1; 
        return true;
    }
    fn func10_3(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        if Self::_func10_3(&mut self.output) {
            state.node = NodeT::Notify10_4;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    fn notify10_4(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.popDepth();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn _string11_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            self.output.value().clear();
        }
        let len = if (self.output.value().len() + data.len()) > 256 { 256 - self.output.value().len() } else { data.len() };
        self.output.value().push_str(&String::from_utf8_lossy(&data[0 .. len]));
    }
    fn string11_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._string11_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Notify11_1;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._string11_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::String11_0;
        return true;
    }
    fn notify11_1(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        self.output.gotVal();
        state.node = NodeT::Loop1_0;
        return true;
    }
    fn loop13_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        return self.uint13_0(state, data);
    }
    fn _uint13_0(&mut self, state: &mut StateT, data: &[u8]) {
        if state.consumed == 0 {
            *self.output.depth() = 0;
        }
        for x in data {
            *self.output.depth() = *self.output.depth()*10 + u32::from(*x - b'0');
        }
    }
    fn uint13_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
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
        let datastart = state.left;
        while state.left < state.right {
            if (state.left + 4) <= state.right {
                if TERMINATOR[usize::from(data[state.left + 0])] {
                    state.left += 0;
                }
                else if TERMINATOR[usize::from(data[state.left + 1])] {
                    state.left += 1;
                }
                else if TERMINATOR[usize::from(data[state.left + 2])] {
                    state.left += 2;
                }
                else if TERMINATOR[usize::from(data[state.left + 3])] {
                    state.left += 3;
                }
                else
                {
                    state.left += 4;
                    continue;
                }
            }
            else if !(TERMINATOR[usize::from(data[state.left + 0])]) {
                state.left += 1;
                continue;
            }
            let left = state.left;
            self._uint13_0(state, &data[datastart .. left]);
            let total = state.consumed + state.left - datastart;
            state.consumed = 0;
            if total >= 1 {
                state.node = NodeT::Loop13_0;
                return true;
            } else {
                state.node = NodeT::NoState;
                return false;
            }
        }
        if datastart < state.left {
            let left = state.left;
            self._uint13_0(state, &data[datastart .. left]);
        }
        state.consumed += state.left - datastart;
        state.node = NodeT::Uint13_0;
        return true;
    }
    fn loop15_0(&mut self, state: &mut StateT, data: &[u8]) -> bool {
        state.node = NodeT::NoState;
        return true;
    }
} // impl
