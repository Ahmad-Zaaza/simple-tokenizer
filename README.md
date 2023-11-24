# Simple tokenizer using the LOL language grammar

This tokenizer takes an input using `readline` and prints the token list to `stdout`.

The printed tokens are in the format: `TOKEN [Type] <TOKEN_TYPE> => <TOKEN>`.

This token only recognizes the following characters in this regex format:

- `[0-9]`for digit tokens.
- `lol[ol*]` for LOL tokens.

and anything else is ignored.

## Usage

```bash
# compile the program
$~ make

# run the program
$~ ./lolTokenizer
```
