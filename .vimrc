call plug#begin()
Plug 'fatih/vim-go', { 'do': ':GoInstallBinaries' }
Plug 'nsf/gocode', { 'rtp': 'vim', 'do': '~/.vim/plugged/gocode/vim/symlink.sh' }
Plug 'vim-syntastic/syntastic'
Plug 'https://github.com/vim-scripts/L9.git'
Plug 'othree/vim-autocomplpop'
call plug#end()
filetype plugin on
set autowrite
set number
set ruler
noremap <C-w :q!<CR>
let sbv_tab_placeholder='»·'
let sbv_space_placeholder='·'
execute "set list listchars=tab:". sbv_tab_placeholder .",trail:". sbv_space_placeholder
execute "set tabstop=". 4
set shiftwidth=4
set tabstop=4
colorscheme molokai
