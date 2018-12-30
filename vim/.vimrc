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
"Plugin 'Lokaltog/vim-powerline'
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
Plugin 'liuchengxu/space-vim-dark'
"Plugin 'Valloric/YouCompleteMe'
Plugin 'derekwyatt/vim-protodef'
Plugin 'scrooloose/nerdtree'
Plugin 'fholgado/minibufexpl.vim'
Plugin 'gcmt/wildfire.vim'
Plugin 'sjl/gundo.vim'
Plugin 'Lokaltog/vim-easymotion'
Plugin 'godlygeek/tabular'
"Plugin 'plasticboy/vim-markdown'
"Plugin 'suan/vim-instant-markdown'
Plugin 'lilydjwg/fcitx.vim'
"markdown 即时浏览
Plugin 'iamcco/markdown-preview.vim'
Plugin 'iamcco/mathjax-support-for-mkdp'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
"Plugin 'scrooloose/nerdtree'
" 插件列表结束
call vundle#end()
filetype plugin indent on
"filetype on
"}}}
"{{{代码折叠
"set fmd=indent
set fdm=marker
"set fdm=syntax
"}}}
"{{{设置
"set showmatch "自动匹配又括号
set smartindent "智能对齐
set autoindent "自动对齐
set ai! "设置自动缩进
setl efm=%A%f:%l:\ %m,%-Z%p^,%-C%.%#
set makeprg=g++\ -Wall\ \ %
"set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
let mapleader=";"
"代码补全
"set completeopt=longest,menu
"set completeopt=preview,menu
"hi Normal ctermfg=252 ctermbg=none
"保存即加载.vimrc
"autocmd BufWritePost $MYVIMRC source $MYVIMRC
"}}}
"{{{映射
map <F9> <Esc>:w<Esc>:!g++ -g % -o %:r1<Esc>
map <F10> <Esc>:!./%:r1<Esc>
map <c-l> <Esc>0i/*<Esc><end>a*/<Esc>
map <c-p> <Esc>0xx<Esc><end>xx
map <c-g> <Esc>:!gdb -q %:r1<Esc>
map <leader>ww  <esc>:w! ~/temp/%<Esc>
map <leader>oi <esc>:vsp %:r.in<esc>
map <leader>oo <esc>:vsp %:r.out<esc>
map <leader>wi <esc>:!cat %:r.in<esc>
map <leader>wo <esc>:!cat %:r.out<esc>
map <leader>bash <esc>:ConqueTermSplit bash<esc>
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
if(has("gui_running"))
set background=dark
"colorscheme solarized
colorscheme space-vim-dark
let g:space_vim_dark_background =234
"colorscheme molokai
"colorscheme phd
endif
"}}}
"{{{ 设置 gvim 显示字体
set guifont=YaHei\ Consolas\ Hybrid\ 11.5
if(has("gui_running"))
let g:Powerline_colorscheme='space-vim-dark'
else
let g:Powerline_colorscheme='solarized256'
endif
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
	call system("wmctrl -ir ".v:windowid." -b toggle,fullscreen")
endf
"全屏开关
map <silent> <F11>:call ToggleFullscreen()<CR>
"自动全屏
autocmd VimEnter * call ToggleFullscreen()
"}}}
"{{{markdown 即时浏览快捷键
"MarkdownPreview
"MarkdownPreviewStop
"nmap <leader>mo MarkdownPreview
"imap <leader>mo MarkdownPreview
"nmap <leader>mc StopMarkdownPreview
"nmap <leader>mc StopMarkdownPreview
"}}}
"{{{vim 打开bash 命令
" ConqueTerm        <command>: 在当前的窗口打开<command>
" ConqueTermSplit   <command>:横向分割一个窗口之后打开<command>
" ConqueTermVSplit  <command>:竖向分割一个窗口之后打开<command>
" ConqueTermTab     <command>:先建一个tab页之后打开<command>
"}}}
"{{{自动插入文件头
autocmd BufNewFile *.cpp :call SetTitle()
function! SetTitle()
        if &filetype =='cpp'
                call setline(1,"/*")
                call append(line("."),"ID:galaxy_6")
                call append(line(".")+1,"LANG:C++")
                call append(line(".")+2,"TASK:".expand("%:r"))
                call append(line(".")+3,"*/")
                call append(line(".")+4,"#include<iostream>")
                call append(line(".")+5,"#include<cstdio>")
                call append(line(".")+6,"using namespace std;")
                call append(line(".")+7,"int main()")
                call append(line(".")+8,"{")
                call append(line(".")+9,"       freopen(\"".expand("%:r").expand(".in\",\"r\",stdin);"))
                call append(line(".")+10,"       freopen(\"".expand("%:r").expand(".out\",\"w\",stdout);"))
                call append(line(".")+11,"}")
        endif
        autocmd BufNewFile * normal G
endfunction
"}}}
"{{{暂无作用
"let var=%:p
"let now='/home/galaxy_yr/YR/USACO'
"if (var==now)
"        if &filetype =='cpp'
"                call append(line("."),"/*")
"                call append(line(".")+1,"ID:galaxy_6")
"                call append(line(".")+2,"LANG:C++")
"                call append(line(".")+3,"TASK:"+%:r)
"                call append(line(".")+4,"*/")
"        endif
"endif
"}}}
"{{{NERDTree
map <leader>n :NERDTreeToggle<cr>
autocmd bufenter * if (winnr("$")==1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q| endif
"}}}
