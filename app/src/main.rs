use rust_crate::DynamicBuffer;

fn main() {
    println!("=== CTORM Practical Application: Log Stream Aggregator ===\n");

    // Initialize our safe Rust dynamic buffer
    let mut log_buffer = DynamicBuffer::with_capacity(32);

    // Simulated real-time server events
    let incoming_logs = vec![
        "[INFO]  2026-08-14 14:30:00 - System daemon started.",
        "[WARN]  2026-08-14 14:30:05 - Memory usage exceeded threshold (78%).",
        "[ERROR] 2026-08-14 14:30:12 - Network timeout on interface eth0.",
        "[INFO]  2026-08-14 14:30:15 - Re-establishing socket connection...",
    ];

    println!("Processing log streams into safe heap memory...");
    for log in incoming_logs {
        log_buffer.append(log);
        log_buffer.append("\n"); // Append newline delimiter
    }

    // Display compiled log output
    println!("\n--- Consolidated Log Output ---");
    print!("{}", log_buffer.as_str());

    // Display memory telemetry
    println!("--- Memory & Buffer Telemetry ---");
    println!("Buffered Length : {} bytes", log_buffer.len());
    println!("Allocated Capacity: {} bytes", log_buffer.capacity());
    println!("\n✅ Memory execution complete. Buffer deallocated automatically via RAII.");
}