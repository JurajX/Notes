# Cargo documentaiton https://doc.rust-lang.org/cargo/

cargo init              # initiates a new project in the current directory
cargo new NAME          # create a project in a new sub-directory
cargo build             # build a project in target/debug or target/release with --release flag
cargo run               # build and run a project in one step (--release flag as above)
cargo check             # build a project without producing a binary; check for errors
cargo clean             # deletes the build files

cargo test              # run all tests in the project
  -- --test-threads=N   # run with N threads, default 1 thread per logical CPU
  -- --show-output      # shows std-out of passing tests
  -- --ignored          # runs the tests annotated with #[ignore]
  -- --include-ignored  # runs ignored and non-ignored tests
  name_filter           # runs only tests that match the filter string
  --test test_file      # runs only integration test from test_file