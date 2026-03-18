// -*- mode: rust; -*-

/**************************************************
 * ATTRIBUTES / CRATE-LEVEL
 **************************************************/

#![allow(dead_code)]
#![cfg_attr(feature = "nightly", feature(test))]

use std::fmt::{self, Debug};
use std::ops::{Add, Deref};

// --------------------------------------------------
// MACROS
// --------------------------------------------------

macro_rules! my_macro {
    ($x:expr) => { $x * 2 };
    ($x:expr, $y:expr) => { $x + $y };
}

macro_rules! variadic {
    ($($x:expr),*) => {
        $(println!("{}", $x);)*
    };
}

// token tree edge case
macro_rules! tt_test {
    ($($tt:tt)*) => { stringify!($($tt)*) };
}

// --------------------------------------------------
// TYPES / STRUCT / ENUM / UNION
// --------------------------------------------------

#[derive(Debug, Clone, Copy)]
struct Point<T> {
    x: T,
    y: T,
}

union MyUnion {
    i: i32,
    f: f32,
}

enum Message<T> {
    Quit,
    Move { x: i32, y: i32 },
    Write(T),
    ChangeColor(i32, i32, i32),
}

// --------------------------------------------------
// TRAITS / IMPL / GENERICS
// --------------------------------------------------

trait MyTrait<T> {
    fn do_something(&self, val: T) -> T;
}

impl<T: Copy + Add<Output = T>> MyTrait<T> for Point<T> {
    fn do_something(&self, val: T) -> T {
        self.x + val
    }
}

// where clause
fn generic_fn<T, U>(x: T, y: U) -> T
where
    T: Copy + Add<Output = T>,
    U: Into<T>,
{
    x + y.into()
}

// --------------------------------------------------
// LIFETIMES
// --------------------------------------------------

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}

// multiple lifetimes
fn lifetimes<'a, 'b: 'a>(x: &'a str, y: &'b str) -> &'a str {
    x
}

// --------------------------------------------------
// FUNCTIONS / CLOSURES
// --------------------------------------------------

fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn closures() {
    let x = 10;

    let simple = |a: i32| a + 1;
    let complex = |a: i32, b: i32| -> i32 { a + b + x };

    let move_closure = move |v: Vec<i32>| v.len();
}

// --------------------------------------------------
// ASYNC / AWAIT
// --------------------------------------------------

async fn async_fn() -> i32 {
    42
}

async fn async_block() {
    let val = async {
        let x = 5;
        x * 2
    }.await;
}

// --------------------------------------------------
// PATTERN MATCHING (ADVANCED)
// --------------------------------------------------

fn pattern_match(msg: Message<i32>) {
    match msg {
        Message::Quit => {}
        Message::Move { x, y } => {}
        Message::Write(v) => {}
        Message::ChangeColor(r, g, b) => {}

        // guards
        Message::Write(v) if v > 10 => {}

        // wildcard
        _ => {}
    }
}

// destructuring
fn destructuring() {
    let (a, b, ..) = (1, 2, 3, 4);

    let Point { x, y } = Point { x: 1, y: 2 };

    let arr = [1, 2, 3];
    match arr {
        [first, .., last] => {}
    }
}

// --------------------------------------------------
// STRINGS / LITERALS
// --------------------------------------------------

fn literals() {
    let s1 = "normal";
    let s2 = r"raw string \n";
    let s3 = r#"raw "quoted" string"#;
    let s4 = r###"multi ### raw ### string"###;

    let b1 = b"bytes";
    let b2 = b'\n';

    let c = 'a';
    let esc = '\x41';

    let i = 1_000_000;
    let hex = 0xff;
    let bin = 0b1010;
    let float = 1e-10;
}

// --------------------------------------------------
// OPERATORS / TRAITS
// --------------------------------------------------

impl<T: Add<Output = T>> Add for Point<T> {
    type Output = Self;

    fn add(self, rhs: Self) -> Self {
        Point { x: self.x + rhs.x, y: self.y + rhs.y }
    }
}

// --------------------------------------------------
// POINTERS / UNSAFE
// --------------------------------------------------

fn unsafe_block() {
    let mut x = 10;

    let ptr = &mut x as *mut i32;

    unsafe {
        *ptr = 20;
    }
}

// --------------------------------------------------
// MODULES / VISIBILITY
// --------------------------------------------------

mod inner {
    pub fn public_fn() {}
    fn private_fn() {}
}

// --------------------------------------------------
// ITERATORS / TRAITS
// --------------------------------------------------

fn iterators() {
    let v = vec![1, 2, 3];

    let res: Vec<_> = v
        .iter()
        .filter(|&&x| x > 1)
        .map(|x| x * 2)
        .collect();
}

// --------------------------------------------------
// ERROR HANDLING
// --------------------------------------------------

fn error_handling() -> Result<i32, String> {
    let val: Option<i32> = Some(10);

    let x = val.ok_or("error")?;

    Ok(x)
}

// --------------------------------------------------
// INVALID / FALLBACK (COMMENTED)
// --------------------------------------------------

// let x = ;
// let s = "unterminated
// fn broken( {
// let y = 1 + * 2;
// macro_rules! bad { ($x:expr => {} }

// --------------------------------------------------
// MAIN
// --------------------------------------------------

fn main() {
    let p = Point { x: 1, y: 2 };

    println!("{:?}", p);

    variadic!(1, 2, 3);

    let val = my_macro!(10);

    println!("{}", val);
}