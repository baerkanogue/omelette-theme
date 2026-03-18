## Overview

**Omelette** – a dark theme with colorful, muted syntax. Mid-saturation colors ensure clarity and contrast without straining the eyes, keeping code readable and visually pleasant.

Compatible with **VSCodium** and **VSCode**.
Made for **Python**, but also compatible with **C**, **C++**, **C#**, **Rust**, and much more *[(see here)](#compatibility)*.

![front](./images/front_page.png)

## Installation

Download the VSIX file in [Releases](https://github.com/baerkanogue/omelette-theme/releases) and install with:
```bash
code --install-extension omelette.vsix
```

Or copy and paste the repo onto the VSCodium / VSCode extensions directory:
```md
# Linux
/home/<your_username>/.vscodium/extensions/
# or
/home/<your_username>/.vscode/extensions/

# Windows
C:\Users\<YourUsername>\.vscodium\extensions\
# or
C:\Users\<YourUsername>\.vscode\extensions\
```


## More customization

**Custom settings:**

To replicate the exact visuals below, apply the settings in **[settings.json](./more/settings.json)**.
Paste them via the command palette: *`Ctrl+P`* → *`Preferences: Open User Settings (JSON)`*.

**Download:**
- Font: *[Fanstasque Sans Mono](https://github.com/belluzj/fantasque-sans)*
- File icons: *[Monokai Pro](https://marketplace.visualstudio.com/items?itemName=monokai.theme-monokai-pro-vscode)*
- Error higlighting: *[Error Lens](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens)*

Click [here](https://coolors.co/ffffff-898989-202020-fc618d-ffa770-ffe69a-8fe09e-9694ff-f3b6ff) to see the **color palette**.

## Gallery

![full_screen](./images/full_page.png)

## Compatibility

|Languages|Support|
|:---|---:|
|Python|Best 🔵|
|C|Good 🟢|
|C++|Good 🟢|
|C#|Good 🟢|
|Rust|Medium 🟡|
|Bash|Medium 🟡|
|Powershell|Medium 🟡|
|Markdown|Basic 🟠|
|Batch|Basic 🟠|
|XML|Basic 🟠|
|JS|None ❌|
|Java|None ❌|
<!-- |PHP|None ❌| -->

Also support various key-value file types such as *dotenv*, *cfg*, *ini files*, etc...

## Notes

This theme is inspired by the visual style of *Monokai Pro (Spectrum Filter)*.

It has been **developed entirely from scratch**, without referencing or using any source code, assets, or implementation details from Monokai Pro or any other proprietary work. **All colors, rules, and design decisions were independently selected and manually defined**.

**No generative AI tools were used in the creation of this theme**, with the exception of the sample scripts provided in the *[sample scripts](./samples/)* directory.
