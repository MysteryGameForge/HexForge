<h1 align="center">HexForge Engine</h1>

<p align="center">
  <img src="./brand/logo.png" alt="hex-forge logo" width="140px" height="140px" />
  <br>
  <em>
    HexForge is a 3D engine
    <br>
    for building desktop games using Editor application
  </em>
</p>

<hr>

## Development Setup

### Prerequisites

- Install [git][git] - includes for cloning a project
- Install [llvm][llvm] - includes to compile a project

### Setting Up a Project

1. Clone a project and move to the project directory

```powershell
git clone https://github.com/MysteryGameForge/HexForge
cd HexForge
```

2. Compile a project

```powershell
# With terminal
scripts\build [debug/release]

# With VSCode
code .
[ctrl+shift+B]
```

3. Run a project

```powershell
# With terminal
build\HexForge.exe

# With VSCode
[F5]
```

## Lisense

[Apache License 2.0](./LICENSE)

[git]: https://git-scm.com/downloads
[llvm]: https://releases.llvm.org/
