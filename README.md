### MEAN

A framework for developing mean-stack apps

## INSTALLATION

# LINUX

To setup

```
cd mean
chmod +x mean
mkdir $HOME/bin
mv mean $HOME/bin/mean
```

To initialize your project, simply

```
mkdir project-name
cd project-name
mean init [-y]
```

# USAGE

To add mongoose models to your backend, use `mean gen model --options`
as `--options` being model names seperated by space.
To open live server, use `mean serve b` for backend.

**NOTE:** Frontend features aren't completed yet. But, you can still use Angular CLI, since this project depends on it. Its aim is to wrap all these packages to a single one for mean applications after all.
