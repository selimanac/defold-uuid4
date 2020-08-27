# uuid4

Defold-uuid4 generator native extension based on [uuid4](https://github.com/gpakosz/uuid4).

All credits goes to [Gregory void★ Pakosz](https://twitter.com/gpakosz)


## Installation

Open your game.project file and in [the dependencies field](http://www.defold.com/manuals/libraries/) under project add:

	https://github.com/selimanac/defold-random/archive/master.zip
	
---

## Usage

### uuid4.generate()

Generates a uuid4 and returns as string.

```lua
local uuid = uuid4.generate()

```

