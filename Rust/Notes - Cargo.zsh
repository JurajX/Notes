# Cargo documentaiton https://doc.rust-lang.org/cargo/

cargo XXX arg1 -- arg2  # arg1 is for cargo, arg2 (after --) is for XXX

cargo init              # initiates a new project in the current directory
cargo new NAME          # create a project in a new sub-directory
cargo build             # build a project in target/debug or target/release with --release flag
cargo run               # build and run a project in one step (--release flag as above)
  --package pkg_name    # run a specific package (in a workspace)
cargo check             # build a project without producing a binary; check for errors
cargo clean             # deletes the build files

cargo test              # run all tests in the project
  name_filter           # runs only tests that match the filter string
  --test test_file      # runs only integration test from test_file
  --package pkg_name    # run a specific package (in a workspace)  -- --test-threads=N   # run with N threads, default 1 thread per logical CPU
  -- --show-output      # shows std-out of passing tests
  -- --ignored          # runs the tests annotated with #[ignore]
  -- --include-ignored  # runs ignored and non-ignored tests

cargo doc               # generates documentation for the project
cargo doc --open        # generates and opens the documentation in a browser

cargo publish               # packages the project and uploads it to crates.io
cargo yank --vers X         # prevents new projects using the specified version
cargo yank --vers X --undo  # re-allows new projects using the specified version
