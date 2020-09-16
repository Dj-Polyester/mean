# MEAN

A framework that creates an integrible backend tree structure. It uses backend only
features of the master branch, have managed your backend environment with a couple of single
line commands, then move the folder wherever you wish.

## INSTALLATION

### LINUX

First clone the branch

```
git clone --single-branch --branch men git@github.com:Dj-Polyester/mean.git
```

To setup

```
cd men
chmod +x men
mkdir $HOME/bin
mv men $HOME/bin/men
```

To initialize your project, simply

```
mkdir project-name
cd project-name
men init [-y]
```

### USAGE

To add mongoose models to your backend, use `men gen model --options`
as `--options` being model names seperated by space.
To open live server, use `men serve`.
