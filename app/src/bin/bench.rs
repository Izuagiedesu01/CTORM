use rust_crate::DynamicBuffer;
use std::time::Instant;

fn main() {
    println!("=== Safe Rust Benchmark (1,000,000 Appends) ===");

    let mut buf = DynamicBuffer::with_capacity(16);

    let start = Instant::now();

    for _ in 0..1_000_000 {
        buf.append("CTORM Benchmark String ");
    }

    let duration = start.elapsed();

    println!("Execution Time : {:.4?} seconds", duration.as_secs_f64());
    println!("Final Capacity : {} bytes", buf.capacity());
    println!("Final Length   : {} bytes", buf.len());
}