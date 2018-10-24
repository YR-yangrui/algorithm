"{{{Vundle
" vundle 环境设置
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
" vundle 管理的插件列表必须位于 vundle#begin() 和 vundle#end() 之间
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'altercation/vim-colors-solarized'
Plugin 'tomasr/molokai'
Plugin 'vim-scripts/phd'
Plugin 'Lokaltog/vim-powerline'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'derekwyatt/vim-fswitch'
Plugin 'kshenoy/vim-signature'
Plugin 'vim-scripts/BOOKMARKS--Mark-and-Highlight-Full-Lines'
Plugin 'majutsushi/tagbar'
"Plugin 'vim-scripts/indexer.tar.gz'
Plugin 'vim-scripts/DfrankUtil'
Plugin 'vim-scripts/vimprj'
Plugin 'dyng/ctrlsf.vim'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'scrooloose/nerdcommenter'
Plugin 'vim-scripts/DrawIt'
Plugin 'SirVer/ultisnips'
"Plugin 'Valloric/YouCompleteMe'
Plugin 'derekwyatt/vim-protodef'
Plugin 'scrooloose/nerdtree'
Plugin 'fholgado/minibufexpl.vim'
Plugin 'gcmt/wildfire.vim'
Plugin 'sjl/gundo.vim'
Plugin 'Lokaltog/vim-easymotion'
Plugin 'suan/vim-instant-markdown'
Plugin 'lilydjwg/fcitx.vim'
" 插件列表结束
call vundle#end()
filetype plugin indent on
"}}}
"{{{代码折叠
"set fmd=indent
set fdm=marker
"set fdm=syntax
"}}}
let mapleader=";"
"hi Normal ctermfg=252 ctermbg=none
"保存即加载.vimrc
autocmd BufWritePost $MYVIMRC source $MYVIMRC
"{{{映射
map <F9> <Esc>:w<Esc>:!g++ -g % -o %:r<Esc>
map <F10> <Esc>:!./%:r<Esc>
map <c-l> <Esc>0i//<Esc>
map <c-p> <Esc>0xx<Esc>
map <c-g> <Esc>:!gdb -q %:r<Esc>
nmap LB 0
nmap LE $
"{{{快速切换窗口
nnoremap <Leader>lw <c-w>l
nnoremap <Leader>hw <c-w>h
nnoremap <Leader>kw <c-w>k
nnoremap <Leader>jw <c-w>j
"}}}
"}}}
"{{{禁止光标闪烁
set gcr=a:block-blinkon0
"}}}
"{{{ 禁止显示滚动条
set guioptions-=l
set guioptions-=L
set guioptions-=r
set guioptions-=R
"}}}
"{{{ 禁止显示菜单和工具条
set guioptions-=m
set guioptions-=T
"}}}
"{{{其他搜索 vim命令补全
set incsearch
set ignorecase
set wildmenu
set nocompatible
"}}}
"{{{辅助信息
set laststatus=2
set ruler
set cursorline
set cursorcolumn
"}}}
"{{{ 配色方案
set background=dark
colorscheme solarized
"colorscheme molokai
"colorscheme phd
"}}}
"{{{ 设置 gvim 显示字体
set guifont=YaHei\ Consolas\ Hybrid\ 11.5
let g:Powerline_colorscheme='solarized256'
syntax keyword cppSTLtype initializer_list
"}}}
"{{{缩进设置
filetype indent on
set expandtab
set nu
"{{{匹配括号
"let g:indent_guides_enable_on_vim_startup=1
"let g:indent_guides_start_level=2
"let g:indent_guides_guide_size=1
"imap <Leader>i <Plug>IndentGuidesToggle
"map <Leader>i <Plug>IndentGuidesToggle
"}}}
"}}}
"{{{ 将外部命令 wmctrl 控制窗口最大化的命令行参数封装成一个 vim 的函数
fun! ToggleFullscreen()
	call system("wmctrl -ir " . v:windowid . " -b toggle,fullscreen")
endf
"全屏开关
map <silent> <F11>:call ToggleFullscreen()<CR>
"自动全屏
autocmd VimEnter * call ToggleFullscreen()
"}}}
