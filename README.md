# avr-template

This is a template repository for AVR C projects. It provides:

- `Makefile` with good defaults for a project using:
  - [ATtiny85](https://www.microchip.com/en-us/product/ATTINY85) microcontroller
  - [SparkFun Tiny AVR Programmer](https://www.sparkfun.com/products/11801)
  - macOS
  - avr-gcc
  - AVRDUDE
- MIT License
- This `README.md` that you should replace
- Kinda sensible `.gitignore` for C

## References

- [*Make: AVR Programming*](https://amzn.to/3H1yxY2) by Elliot Williams
  - Example code: <https://github.com/hexagon5un/AVR-Programming>
- [Using the TinyProgrammer](http://highlowtech.org/?p=1801) by High-Low Tech Group, MIT Media Lab
- [Using avr-gcc](https://gcc.gnu.org/wiki/avr-gcc#Using_avr-gcc)
- [AVRDUDE documentation](https://www.nongnu.org/avrdude/user-manual/avrdude.html)
- [100+ Projects on ATtiny13](https://blog.podkalicki.com/100-projects-on-attiny13/) by Łukasz Podkalicki

## Install the dependencies

In macOS, use Homebrew:

```shell
brew install avr-gcc avrdude
```

For any other OS, you're on your own, but SparkFun's [Tiny AVR Programmer Hookup Guide](https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide) should help a lot.
