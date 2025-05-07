# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:$HOME/.local/bin:/usr/local/bin:$PATH

# Path to your Oh My Zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time Oh My Zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="robbyrussell"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='nvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch $(uname -m)"

# Set personal aliases, overriding those provided by Oh My Zsh libs,
# plugins, and themes. Aliases can be placed here, though Oh My Zsh
# users are encouraged to define aliases within a top-level file in
# the $ZSH_CUSTOM folder, with .zsh extension. Examples:
# - $ZSH_CUSTOM/aliases.zsh
# - $ZSH_CUSTOM/macos.zsh
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

c() {
    if [[ $# -eq 0 ]]; then
        echo "Usage: c <source_file (with or without .cpp extension)>"
        return 1
    fi

    for file in "$@"; do
        # Add .cpp extension if not provided
        if [[ "${file##*.}" != "cpp" ]]; then
            file="${file}.cpp"
        fi

        # Get the base name of the file (remove the path and extension)
        base_name=$(basename "$file" .cpp)

        # Compile with the provided options, outputting to the base name
        g++ -Wall -Wconversion -Wfatal-errors -g -std=c++14 -fsanitize=undefined,address -o "$base_name" "$file"

        # Check if compilation was successful
        if [[ $? -eq 0 ]]; then
            # Make the output executable
            chmod +x "$base_name"
            echo "Compilation successful: ./$base_name"
        else
            echo "Compilation failed for $file"
        fi
    done
}


clip() {
    if [[ $# -eq 0 ]]; then
        echo "Usage: clip <file>"
        return 1
    fi

    if [[ ! -f "$1" ]]; then
        echo "Error: '$1' is not a valid file."
        return 1
    fi

    # Pipe the file contents to xclip
    cat "$1" | xclip -sel clip

    if [[ $? -eq 0 ]]; then
        echo "Contents of '$1' copied to clipboard."
    else
        echo "Failed to copy contents of '$1' to clipboard."
    fi
}

mkp() {
    if [[ $# -ne 1 ]]; then
        echo "Usage: mkp <filename>"
        return 1
    fi

    # Get the filename and ensure it has a .cpp extension
    local filename="$1"
    if [[ "${filename##*.}" != "cpp" ]]; then
        filename="${filename}.cpp"
    fi

    # Generate the current timestamp
    local current_time=$(date +"%d.%m.%Y %H:%M:%S")

    # Template with placeholders for dynamic content
    local template="
/**
 *    author:  antennaevy
 *    created: {datetime}
**/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);



  return 0;
}
"

    # Replace {datetime} in the template with the current timestamp
    local file_content=$(echo -e "${template//\{datetime\}/$current_time}")

    # Create the .cpp file with the template content
    echo -e "$file_content" > "$filename"

    echo "Created file '$filename'"
}

mkc() {
    if [[ $# -ne 1 ]]; then
        echo "Usage: mkc <number_of_folders>"
        return 1
    fi

    # Ensure the input is a valid number
    if ! [[ "$1" =~ ^[0-9]+$ ]]; then
        echo "Error: Argument must be a positive integer."
        return 1
    fi

    # Get the number of folders to create
    local N="$1"

    # Check if the number exceeds 26 (alphabet limit)
    if (( N > 26 )); then
        echo "Error: Maximum of 26 folders can be created (a-z)."
        return 1
    fi

    # Create folders and files
    for ((i=0; i<N; i++)); do
        # Calculate the folder name (a, b, c, ...)
        local folder_name=$(printf "\\x$(printf %x $((97 + i)))") # ASCII value for 'a' is 97

        # Create the folder
        mkdir -p "$folder_name"

        # Call mkp to create the .cpp file in the folder
        mkp "$folder_name/$folder_name"
    done
}

cin() {
    if [[ $# -ne 1 ]]; then
        echo "Usage: cin <filename (without extension)>"
        return 1
    fi

    # Append .in to the provided filename
    local filename="$1.in"

    # Use xclip, pbpaste, or wl-paste to fetch clipboard content
    if command -v xclip &> /dev/null; then
        # Linux with xclip
        xclip -o -sel clip > "$filename"
    elif command -v pbpaste &> /dev/null; then
        # macOS with pbpaste
        pbpaste > "$filename"
    elif command -v wl-paste &> /dev/null; then
        # Wayland clipboard manager
        wl-paste > "$filename"
    else
        echo "Error: No clipboard utility found (xclip, pbpaste, or wl-paste)."
        return 1
    fi

    # Confirm file creation
    if [[ -f "$filename" ]]; then
        echo "File '$filename' created with clipboard content."
    else
        echo "Error: Failed to create file '$filename'."
    fi
}

cout() {
    if [[ $# -ne 1 ]]; then
        echo "Usage: cout <filename (without extension)>"
        return 1
    fi

    # Append .out to the provided filename
    local filename="$1.out"

    # Use xclip, pbpaste, or wl-paste to fetch clipboard content
    if command -v xclip &> /dev/null; then
        # Linux with xclip
        xclip -o -sel clip > "$filename"
    elif command -v pbpaste &> /dev/null; then
        # macOS with pbpaste
        pbpaste > "$filename"
    elif command -v wl-paste &> /dev/null; then
        # Wayland clipboard manager
        wl-paste > "$filename"
    else
        echo "Error: No clipboard utility found (xclip, pbpaste, or wl-paste)."
        return 1
    fi

    # Confirm file creation
    if [[ -f "$filename" ]]; then
        echo "File '$filename' created with clipboard content."
    else
        echo "Error: Failed to create file '$filename'."
    fi
}

rtc() {
    if [[ $# -lt 1 ]]; then
        echo "Usage: rtc <executable> [--exact]"
        return 1
    fi

    local executable="$1"
    local exact=false

    # Check for the --exact flag
    if [[ "$2" == "--exact" ]]; then
        exact=true
    fi

    # Check if the executable exists
    if [[ ! -x "$executable" ]]; then
        echo "Error: Executable '$executable' not found or not executable."
        return 1
    fi

    echo ""

    local verdict="AC" # Overall verdict

    # Loop through all .in files in the current directory
    for input_file in *.in; do
        local base_name="${input_file%.in}"
        local output_file="${base_name}.out"

        # Create temporary files
        local temp_input="Input"
        local temp_output="Output"
        local temp_expected="Expected"

        # Write the .in file content to the Input file
        cp "$input_file" "$temp_input"

        # Execute the program with the .in file as input and write the output to the Output file
        ./"$executable" < "$input_file" > "$temp_output"

        # Write the expected output to the Expected file
        if [[ -f "$output_file" ]]; then
            cp "$output_file" "$temp_expected"
        else
            echo "Error: Missing $output_file" > "$temp_expected"
            verdict="WA"
        fi

        # Display Input, Output, and Expected files using batcat (or cat as fallback)
        echo -e "\033[1;34m===== $input_file =====\033[0m"

        if command -v batcat &> /dev/null; then
            echo -e "\033[1;33m== Input ==\033[0m"
            batcat "$temp_input"

            echo -e "\033[1;33m== Output ==\033[0m"
            batcat "$temp_output"

            echo -e "\033[1;33m== Expected ==\033[0m"
            batcat "$temp_expected"
        else
            echo -e "\033[1;33m== Input ==\033[0m"
            cat "$temp_input"

            echo -e "\033[1;33m== Output ==\033[0m"
            cat "$temp_output"

            echo -e "\033[1;33m== Expected ==\033[0m"
            cat "$temp_expected"
        fi

        # Compare Output with Expected
        if [[ "$exact" == true ]]; then
            # Exact comparison
            if [[ -f "$output_file" && "$(cat "$temp_output")" == "$(cat "$output_file")" ]]; then
                echo -e "\033[1;32mVerdict: AC\033[0m"
            else
                echo -e "\033[1;31mVerdict: WA\033[0m"
                verdict="WA"
            fi
        else
            # Ignore trailing whitespaces and end lines
            local trimmed_output=$(sed 's/[[:space:]]*$//' "$temp_output" | sed '/^$/d')
            local trimmed_expected=$(sed 's/[[:space:]]*$//' "$temp_expected" | sed '/^$/d')

            if [[ -f "$output_file" && "$trimmed_output" == "$trimmed_expected" ]]; then
                echo -e "\033[1;32mVerdict: AC\033[0m"
            else
                echo -e "\033[1;31mVerdict: WA\033[0m"
                verdict="WA"
            fi
        fi

        # Add a blank line for separation between test cases
        echo ""
        # Cleanup temporary files
        rm -f "$temp_input" "$temp_output" "$temp_expected"
    done

    # Add a blank line before the final verdict
    echo -e "\033[1;34mFinal Verdict: \033[0m"
    if [[ "$verdict" == "AC" ]]; then
        echo -e "\033[1;32mAll test cases passed! (AC)\033[0m"
    else
        echo -e "\033[1;31mSome test cases failed. (WA)\033[0m"
    fi
    echo ""
}


alias reload="source ~/.zshrc"
alias config="lvim ~/.zshrc"
alias cat="batcat"

export PATH="$PATH:/home/jose/.local/bin/"
