/// A memory-safe dynamic string buffer in Rust.
#[derive(Debug, PartialEq, Eq)]
pub struct DynamicBuffer {
    data: Vec<u8>,
}

impl DynamicBuffer {
    pub fn with_capacity(capacity: usize) -> Self {
        Self {
            data: Vec::with_capacity(capacity),
        }
    }

    pub fn append(&mut self, text: &str) {
        self.data.extend_from_slice(text.as_bytes());
    }

    pub fn clear(&mut self) {
        self.data.clear();
    }

    pub fn len(&self) -> usize {
        self.data.len()
    }

    pub fn capacity(&self) -> usize {
        self.data.capacity()
    }

    pub fn as_str(&self) -> &str {
        std::str::from_utf8(&self.data).unwrap_or("")
    }

    pub fn is_empty(&self) -> bool {
        self.data.is_empty()
    }
}