# Rust Compiler (rustc) Options
-C opt-level=3          # Highest optimization level
-C lto=yes              # Enables Link Time Optimization (LTO)
-C target-cpu=native    # Optimizes for the CPU you're compiling on
-C codegen-units=1      # Forces single codegen unit
-C strip=symbols        # Removes all symbol information