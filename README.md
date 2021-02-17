# Exploring memberwise and groupwise splitting in ROOT

This is just a tiny playground to explore the serialisation features of ROOT
to be able to reverse engineer it.

Run `make` and then `./write_files` to create a few ROOT files with some
dummy data streamed with different options. Feel free to adjust the parameters,
alter the `TWhatever` class and find out how to actually enable memberwise
splitting `;)`.

One of the main discussion place is this issue in `uproot4`: https://github.com/scikit-hep/uproot4/issues/38

Any ideas, feedback, input is highly appreciated as this is still work in progress.
