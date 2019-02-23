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
Plugin 'vim-ctrlspace/vim-ctrlspace'
Plugin 'vim-scripts/indexer.tar.gz'
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
"set tabstop=4
set smartindent "智能对齐
set autoindent "自动对齐
set ai! "设置自动缩进
setl efm=%A%f:%l:\ %m,%-Z%p^,%-C%.%#
set makeprg=g++\ -Wall\ \ %
set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
let mapleader=";"
"代码补全
"set completeopt=longest,menu
"set completeopt=preview,menu
"hi Normal ctermfg=252 ctermbg=none
"保存即加载.vimrc
autocmd BufWritePost $MYVIMRC source $MYVIMRC
"}}}
"{{{映射
map <F8> <esc>ggVG"+y<esc>
map <F9> <Esc>:w<Esc>:!g++ -g % -o %:r1<Esc>
map <F10> <Esc>:!./%:r1<Esc>
map <c-l> <Esc>0i/*<Esc><end>a*/<Esc>
map <c-p> <Esc>0xx<Esc><end>xx
map <c-g> <Esc>:!gdb -q %:r1<Esc>
map <leader>ww  <esc>:w! ~/temp/%<Esc>
map <leader>to <esc>:vsp ~/temp/%<esc>
map <leader>oi <esc>:vsp %:r.in<esc>
map <leader>oo <esc>:vsp %:r.out<esc>
map <leader>wi <esc>:!cat %:r.in<esc>
map <leader>wo <esc>:!cat %:r.out<esc>
map <leader>bash <esc>:ConqueTermSplit bash<esc>
map ,n <esc>:tabn<esc>
map ,p <esc>:tabp<esc>
map <leader>hl <c-w>>
map <leader>hh <c-w><
map <c-a> ggVG
"<leader>cc 紧贴代码加注释
"<leader>cb 代码最前面加注释
"<leader>cu 解开注释
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
"set background=dark
"colorscheme solarized
"let g:space_vim_dark_background =234
"colorscheme space-vim-dark
"hi Comment guifg=#5C6370 ctermfg=59
"set termguicolors
"hi LineNr ctermbg=NONE guibg=NONE
colorscheme molokai
"colorscheme phd
endif
"}}}
"{{{ 设置 gvim 显示字体
if(has("gui_running"))
set guifont=YaHei\ Consolas\ Hybrid\ 11.5
"let g:Powerline_colorscheme='space-vim-dark'
else
"let g:Powerline_colorscheme='solarized256'
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
map <silent> <F11> :call ToggleFullscreen()<CR>
"自动全屏
autocmd VimEnter * call ToggleFullscreen()
"}}}
"{{{markdown 即时浏览快捷键
"MarkdownPreview
"MarkdownPreviewStop
nmap <leader>mo <esc>:MarkdownPreview<esc>
imap <leader>mo <esc>:MarkdownPreview<esc>
nmap <leader>mc <esc>:StopMarkdownPreview><esc>
nmap <leader>mc <esc>:StopMarkdownPreview<esc>
"}}}
"{{{vim 打开bash 命令
" ConqueTerm        <command>: 在当前的窗口打开<command>
" ConqueTermSplit   <command>:横向分割一个窗口之后打开<command>
" ConqueTermVSplit  <command>:竖向分割一个窗口之后打开<command>
" ConqueTermTab     <command>:先建一个tab页之后打开<command>
"}}}
"{{{自动插入文件头
function! CurDir()
        let curdir=substitute(getcwd(),$HOME,"~","g")
        return curdir
endfunction
autocmd BufNewFile *.cpp :call SetTitle()
function! SetTitle()
        if &filetype =='cpp'
                if(CurDir()=='~/YR/USACO')
                        call setline(1,"/*")
                        call append(line("."),"ID:galaxy_6")
                        call append(line(".")+1,"LANG:C++")
                        call append(line(".")+2,"TASK:".expand("%:r"))
                        call append(line(".")+3,"*/")
                        call append(line(".")+4,"#include<iostream>")
                        call append(line(".")+5,"#include<cstdio>")
                        call append(line(".")+6,"struct IO{")
                        call append(line(".")+7,"       template<typename T>")
                        call append(line(".")+8,"               IO & operator>>(T&res)")
                        call append(line(".")+9,"               {")
                        call append(line(".")+10,"                      char ch=getchar();")
                        call append(line(".")+11,"                      T q=1;")
                        call append(line(".")+12,"                      while(ch<'0' or ch>'9'){if(ch=='-')q=-q;ch=getchar();}") 
                        call append(line(".")+13,"                      res=(ch^48);") 
                        call append(line(".")+14,"                      while((ch=getchar())>='0' and ch<='9')")
                        call append(line(".")+15,"                      res=(res<<1)+(res<<3)+(ch^48);") 
                        call append(line(".")+16,"                      res*=q;") 
                        call append(line(".")+17,"                      return *this;") 
                        call append(line(".")+18,"              }")
                        call append(line(".")+19,"}cin;")
                        call append(line(".")+20,"using std::cout; using std::endl;")
                        call append(line(".")+21,"int main()")
                        call append(line(".")+22,"{")
                        call append(line(".")+23,"       freopen(\"".expand("%:r").expand(".in\",\"r\",stdin);"))
                        call append(line(".")+24,"       freopen(\"".expand("%:r").expand(".out\",\"w\",stdout);"))
                        call append(line(".")+25,"}")
                elseif expand("%")=="dp.cpp"
                        call setline(1,"/*******************************")
                        call append(line("."),"Author:galaxy yr")
                        call append(line(".")+1,"LANG:C++")
                        call append(line(".")+2,"Created Time:".strftime("%c"))
                        call append(line(".")+3,"*******************************/")
                        call append(line(".")+4,"#include<fstream>")
                        call append(line(".")+5,"#include<string>")
                        call append(line(".")+6,"#include<ctime>")
                        call append(line(".")+7,"#include<cstdlib>")
                        call append(line(".")+8,"#include<iostream>")
                        call append(line(".")+9,"using namespace std;")
                        call append(line(".")+10,"const string name1(),name2();")
                        call append(line(".")+11,"ifstream f1(name1),f2(name2);")
                        call append(line(".")+12,"int main()")
                        call append(line(".")+13,"{")
                        call append(line(".")+14,"       while(true)")
                        call append(line(".")+15,"       {")
                        call append(line(".")+16,"               system(\"./rand1\");system(\"./1\");system(\"./1\");")
                        call append(line(".")+17,"               char ch1,ch2; int k=-1;f1.clear();f2.clear();")
                        call append(line(".")+18,"               while(f1 and f2)")
                        call append(line(".")+19,"               {")
                        call append(line(".")+20,"                       f1>>ch1;f2>>ch2;")
                        call append(line(".")+21,"                       if(ch1=='\\n')k++;")
                        call append(line(".")+22,"                       if(ch1!=ch2)cout<<\"NO. on line:\"<<k<<endl;")
                        call append(line(".")+23,"                       else cout<<\"Yes\"<<endl;")
                        call append(line(".")+24,"               }")
                        call append(line(".")+25,"       }")
                        call append(line(".")+26,"       return 0;")
                        call append(line(".")+27,"}")
                else
                        call setline(1,"/*******************************")
                        call append(line("."),"Author:galaxy yr")
                        call append(line(".")+1,"LANG:C++")
                        call append(line(".")+2,"Created Time:".strftime("%c"))
                        call append(line(".")+3,"*******************************/")
                        call append(line(".")+4,"#include<iostream>")
                        call append(line(".")+5,"#include<cstdio>")
                        call append(line(".")+6,"struct IO{")
                        call append(line(".")+7,"       template<typename T>")
                        call append(line(".")+8,"               IO & operator>>(T&res)")
                        call append(line(".")+9,"               {")
                        call append(line(".")+10,"                      char ch=getchar();")
                        call append(line(".")+11,"                      T q=1;")
                        call append(line(".")+12,"                      while(ch<'0' or ch>'9'){if(ch=='-')q=-q;ch=getchar();}") 
                        call append(line(".")+13,"                      res=(ch^48);") 
                        call append(line(".")+14,"                      while((ch=getchar())>='0' and ch<='9')")
                        call append(line(".")+15,"                      res=(res<<1)+(res<<3)+(ch^48);") 
                        call append(line(".")+16,"                      res*=q;") 
                        call append(line(".")+17,"                      return *this;") 
                        call append(line(".")+18,"              }")
                        call append(line(".")+19,"}cin;")
                        call append(line(".")+20,"using std::cout; using std::endl;")
                        call append(line(".")+21,"int main()")
                        call append(line(".")+22,"{")
                        call append(line(".")+23,"        freopen(\"".expand("%:r").expand(".in\",\"r\",stdin);"))
                        call append(line(".")+24,"        freopen(\"".expand("%:r").expand(".out\",\"w\",stdout);"))
                        call append(line(".")+25,"}")
                endif
        endif
        autocmd BufNewFile * normal G
endfunction
"}}}
"{{{NERDTree
nmap ner <esc>:NERDTreeToggle<cr>
" 设置 NERDTree 子窗口宽度
let NERDTreeWinSize=22
" 设置 NERDTree 子窗口位置
let NERDTreeWinPos="right"
" 显示隐藏文件
let NERDTreeShowHidden=1
" NERDTree 子窗口中不显示冗余帮助信息
let NERDTreeMinimalUI=1
" 删除文件时自动删除文件对应 buffer
let NERDTreeAutoDeleteBuffer=1

autocmd bufenter * if (winnr("$")==1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q| endif
"}}}
"{{{airline
set t_Co=256
let g:airline_powerline_fonts=1
let g:airline_theme='zenburn'
let g:airline#extensions#tabline#enabled=1
let g:airline#extensions#tabline#left_alt_sep=' '
let g:airline#extensions#tabline#buffer_nr_show=' '
"}}}
"{{{ 显示/隐藏 MiniBufExplorer 窗口
map <Leader>bl :MBEToggle<cr>
" buffer 切换快捷键
map <C-Tab> :MBEbn<cr>
map <C-S-Tab> :MBEbp<cr>
"}}}
"{{{cpp-enhanced-highlight
let g:cpp_class_scope_highlight=1
let g:cpp_member_variable_highlight=1
let g:cpp_concepts_highlight=1
let g:cpp_class_decl_highlight=1
"let g:cpp_experimental_simple_template_highlight=1
"}}}
"{{{ctrlspace
set nocompatible
set hidden
set showtabline=0
"}}}
"{{{ 抄的
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
" 从第二层开始可视化显示缩进
let g:indent_guides_start_level=2
" 色块宽度
let g:indent_guides_guide_size=1
" 快捷键 i 开/关缩进可视化
nmap <silent> <Leader>i <Plug>IndentGuidesToggle
nmap <silent> <Leader>sw :FSHere<cr>

" 自定义 vim-signature 快捷键
let g:SignatureMap = {
        \ 'Leader'             :  "m",
        \ 'PlaceNextMark'      :  "m,",
        \ 'ToggleMarkAtLine'   :  "m.",
        \ 'PurgeMarksAtLine'   :  "m-",
        \ 'DeleteMark'         :  "dm",
        \ 'PurgeMarks'         :  "mda",
        \ 'PurgeMarkers'       :  "m<BS>",
        \ 'GotoNextLineAlpha'  :  "']",
        \ 'GotoPrevLineAlpha'  :  "'[",
        \ 'GotoNextSpotAlpha'  :  "`]",
        \ 'GotoPrevSpotAlpha'  :  "`[",
        \ 'GotoNextLineByPos'  :  "]'",
        \ 'GotoPrevLineByPos'  :  "['",
        \ 'GotoNextSpotByPos'  :  "mn",
        \ 'GotoPrevSpotByPos'  :  "mp",
        \ 'GotoNextMarker'     :  "[+",
        \ 'GotoPrevMarker'     :  "[-",
        \ 'GotoNextMarkerAny'  :  "]=",
        \ 'GotoPrevMarkerAny'  :  "[=",
        \ 'ListLocalMarks'     :  "ms",
        \ 'ListLocalMarkers'   :  "m?"
        \ }

" <<

" >>
" 标签列表

" 设置 tagbar 子窗口的位置出现在主编辑区的左边
let tagbar_left=1
" 设置显示／隐藏标签列表子窗口的快捷键。速记：identifier list by tag
nnoremap <Leader>ilt :TagbarToggle<CR>
" 设置标签子窗口的宽度
let tagbar_width=32
" tagbar 子窗口中不显示冗余帮助信息
let g:tagbar_compact=1
" 设置 ctags 对哪些代码标识符生成标签
let g:tagbar_type_cpp = {
     \ 'ctagstype' : 'c++',
     \ 'kinds'     : [
         \ 'c:classes:0:1',
         \ 'd:macros:0:1',
         \ 'e:enumerators:0:0', 
         \ 'f:functions:0:1',
         \ 'g:enumeration:0:1',
         \ 'l:local:0:1',
         \ 'm:members:0:1',
         \ 'n:namespaces:0:1',
         \ 'p:functions_prototypes:0:1',
         \ 's:structs:0:1',
         \ 't:typedefs:0:1',
         \ 'u:unions:0:1',
         \ 'v:global:0:1',
         \ 'x:external:0:1'
     \ ],
     \ 'sro'        : '::',
     \ 'kind2scope' : {
         \ 'g' : 'enum',
         \ 'n' : 'namespace',
         \ 'c' : 'class',
         \ 's' : 'struct',
         \ 'u' : 'union'
     \ },
     \ 'scope2kind' : {
         \ 'enum'      : 'g',
         \ 'namespace' : 'n',
         \ 'class'     : 'c',
         \ 'struct'    : 's',
         \ 'union'     : 'u'
     \ }
\ }

" <<

" >>
" 代码导航
 
" 基于标签的代码导航

" 设置插件 indexer 调用 ctags 的参数
" 默认 --c++-kinds=+p+l，重新设置为 --c++-kinds=+l+p+x+c+d+e+f+g+m+n+s+t+u+v
" 默认 --fields=+iaS 不满足 YCM 要求，需改为 --fields=+iaSl
let g:indexer_ctagsCommandLineOptions="--c++-kinds=+l+p+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"

" 正向遍历同名标签
nmap <Leader>tn :tnext<CR>
" 反向遍历同名标签
nmap <Leader>tp :tprevious<CR>

" 基于语义的代码导航

"nnoremap <leader>jc :YcmCompleter GoToDeclaration<CR>
"" 只能是 #include 或已打开的文件
"nnoremap <leader>jd :YcmCompleter GoToDefinition<CR>

" <<

" >>
" 查找

" 使用 ctrlsf.vim 插件在工程内全局查找光标所在关键字，设置快捷键。快捷键速记法：search in project
nnoremap <Leader>sp :CtrlSF<CR>

" <<

" >>
" 内容替换

" 快捷替换
let g:multi_cursor_next_key='<S-n>'
let g:multi_cursor_skip_key='<S-k>'

" 精准替换
" 替换函数。参数说明：
" confirm：是否替换前逐一确认
" wholeword：是否整词匹配
" replace：被替换字符串
function! Replace(confirm, wholeword, replace)
    wa
    let flag = ''
    if a:confirm
        let flag .= 'gec'
    else
        let flag .= 'ge'
    endif
    let search = ''
    if a:wholeword
        let search .= '\<' . escape(expand('<cword>'), '/\.*$^~[') . '\>'
    else
        let search .= expand('<cword>')
    endif
    let replace = escape(a:replace, '/\&~')
    execute 'argdo %s/' . search . '/' . replace . '/' . flag . '| update'
endfunction
" 不确认、非整词
nnoremap <Leader>R :call Replace(0, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" 不确认、整词
nnoremap <Leader>rw :call Replace(0, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" 确认、非整词
nnoremap <Leader>rc :call Replace(1, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" 确认、整词
nnoremap <Leader>rcw :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
nnoremap <Leader>rwc :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>

" <<

" 模板补全
" UltiSnips 的 tab 键与 YCM 冲突，重新设定
"let g:UltiSnipsSnippetDirectories=["mysnippets"]
"let g:UltiSnipsExpandTrigger="<leader><tab>"
"let g:UltiSnipsJumpForwardTrigger="<leader><tab>"
"let g:UltiSnipsJumpBackwardTrigger="<leader><s-tab>"

"" >>
"" YCM 补全

"" YCM 补全菜单配色
"" 菜单
"highlight Pmenu ctermfg=2 ctermbg=3 guifg=#005f87 guibg=#EEE8D5
"" 选中项
"highlight PmenuSel ctermfg=2 ctermbg=3 guifg=#AFD700 guibg=#106900

"" 补全功能在注释中同样有效
"let g:ycm_complete_in_comments=1

"" 允许 vim 加载 .ycm_extra_conf.py 文件，不再提示
"let g:ycm_confirm_extra_conf=0

"" 开启 YCM 标签补全引擎
"let g:ycm_collect_identifiers_from_tags_files=0
""" 引入 C++ 标准库 tags
""set tags+=/data/misc/software/app/vim/stdcpp.tags
""set tags+=/data/misc/software/app/vim/sys.tags

"" YCM 集成 OmniCppComplete 补全引擎，设置其快捷键
"inoremap <leader>; <C-x><C-o>

"" 补全内容不以分割子窗口形式出现，只显示补全列表
"set completeopt-=preview

"" 从第一个键入字符就开始罗列匹配项
"let g:ycm_min_num_of_chars_for_completion=1

"" 禁止缓存匹配项，每次都重新生成匹配项
"let g:ycm_cache_omnifunc=0

"" 语法关键字补全
"let g:ycm_seed_identifiers_with_syntax=1

"" <<
 
"" >>
"" 由接口快速生成实现框架

"" 成员函数的实现顺序与声明顺序一致
"let g:able_protodef_sorting=1

"" <<

"" >>
"" 库信息参考
 
"" 启用:Man命令查看各类man信息
"source $VIMRUNTIME/ftplugin/man.vim

"" 定义:Man命令查看各类man信息的快捷键
"nmap <Leader>man :Man 3 <cword><CR>
""}}}
