<h1 align="center">Welcome to Enhanced Push 👋</h1>
<p>
  <a href="https://twitter.com/Sn0wDev__" target="_blank">
    <img alt="Twitter: Sn0wDev__" src="https://img.shields.io/twitter/follow/Sn0wDev__.svg?style=social" />
  </a>
</p>

## General

I made this program to push only with one command and a formatted commit message.
This is the new version of my previous tool Simple Push. In the future, we can configure the message format, choose which files we want to commit, and more.

## Technical

I programmed this tool in C++, to train my skills and especially to boost my productivity.

## Install

```sh
git clone https://github.com/Sn00ww/enhanced-push.git
```

## Build

```sh
make        # Build the tool
make clean  # Clean build
make re     # Rebuild the tool (clean and build)
```

## Usage

```sh
./bin/push -m <message> [-a] [-p]
# -m <message>: Commit message
# -a: Add all files to commit (git add .)
# -p: Push to remote (git push)
```

## Author

👤 **Sn0w**

* Twitter: [@Sn0wDev__](https://twitter.com/Sn0wDev__)
* Github: [@Sn00ww](https://github.com/Sn00ww)