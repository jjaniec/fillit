let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <F2> :calc CreateSergeHeader()
imap <F1> :call Create42Header()
imap <S-Down> :+5
imap <S-Up> :-5
imap <S-Left> <Left><Left><Left><Left><Left>
imap <S-Right> <Right><Right><Right><Right><Right>
imap <F4> :set invcursorlinea
imap <F3> :set invrelativenumbera
nmap <NL> j
nmap <Down> j
nmap <C-Down> j
nmap  k
nmap <Up> k
nmap <C-Up> k
nmap  h
nmap <Left> h
nmap <C-Left> h
nmap  l
nmap <Right> l
nmap <C-Right> l
nmap ,tc <Plug>Colorizer
nmap ,nn :call NormFile()
nmap ,d9d :call RemoveBalisePart(9)
nmap ,d8d :call RemoveBalisePart(8)
nmap ,d7d :call RemoveBalisePart(7)
nmap ,d6d :call RemoveBalisePart(6)
nmap ,d5d :call RemoveBalisePart(5)
nmap ,d4d :call RemoveBalisePart(4)
nmap ,d3d :call RemoveBalisePart(3)
nmap ,d2d :call RemoveBalisePart(2)
nmap ,d1d :call RemoveBalisePart(1)
nmap ,d0d :call RemoveBalisePart(0)
vmap ,<9 `<O//<d9>==`>o//</d9>==<Up>
vmap ,<8 `<O//<d8>==`>o//</d8>==<Up>
vmap ,<7 `<O//<d7>==`>o//</d7>==<Up>
vmap ,<6 `<O//<d6>==`>o//</d6>==<Up>
vmap ,<5 `<O//<d5>==`>o//</d5>==<Up>
vmap ,<4 `<O//<d4>==`>o//</d4>==<Up>
vmap ,<3 `<O//<d3>==`>o//</d3>==<Up>
vmap ,<2 `<O//<d2>==`>o//</d2>==<Up>
vmap ,<1 `<O//<d1>==`>o//</d1>==<Up>
vmap ,<0 `<O//<d0>==`>o//</d0>==<Up>
nmap ,dl\ :call NormDecommentDeleteLineComment('d')
nmap ,dl/ :call NormCommentDeleteLineComment('d')
nmap ,dld :call NormRemoveDeleteLineComment('d')
nmap ,d/d :call NormRemoveComment()
nmap ,\ :call SergeDecommentRegion()
vmap ,\ :call SergeDecommentRegion()
nmap ,/ :call SergeCommentRegion()
vmap ,/ :call SergeCommentRegion()
nmap ,* o*/<Up>O/*=2<Down><Down>
vmap ,* `>a*/`<i/*
vmap ,{ :call PutAcolade()
nmap ,{ o}<Up>O{=2<Down><Down>
vmap ," `<i"`>a<Right>"
vmap ,' `<i'`>a<Right>'
vmap ,[ `<i[`>a<Right>]
vmap ,( `<i(`>a<Right>)
nmap ,yff :call FunctionSelect()
nmap ,yf5 /^\w\+[\t ]*\**\w\+(.*)\n"ayyn"Ayyn"Ayyn"Ayyn"Ayy:silent!/kjdhkjdhakfdf:echo "5 function yanked in buffer A"
nmap ,yf4 /^\w\+[\t ]*\**\w\+(.*)\n"ayyn"Ayyn"Ayyn"Ayyn:silent!/kjdhkjdhakfdf:echo "4 function yanked in buffer A"
nmap ,yf3 /^\w\+[\t ]*\**\w\+(.*)\n"ayyn"Ayyn"Ayyn:silent!/kjdhkjdhakfdf:echo "3 function yanked in buffer A"
nmap ,yf2 /^\w\+[\t ]*\**\w\+(.*)\n"ayyn"Ayyn":silent!/kjdhkjdhakfdf:echo "2 function yanked in buffer A"
nmap ,yf1 /^\w\+[\t ]*\**\w\+(.*)\n"ayyn:silent!/kjdhkjdhakfdf:echo "1 function yanked in buffer A"
nmap ,ff /^\w\+[\t ]*\**\w\+(.*)\n
nmap ,; :call PointVirgule()
nmap ,b :ConqueTerm bash<Up><Down>
nmap ,z :ConqueTerm zsh<Up><Down>
nmap ,g :call NavFichier()=
nmap ,V :so $MYVIMRC
nmap , :so $MYVIMRC
nmap ,v :so $MYVIMRC
nmap ,ma :set mouse=a
nmap ,mm :set mouse=
nmap ,<C-S-Tab> :tabmove -1
nmap ,<S-Tab> :tabmove -1
nmap ,<C-Tab> :tabmove +1
nmap ,	 :tabmove +1
nmap ,<F5> :wa:mksession!:wqa
nmap ,c :!cat %
vmap ,d :'<, '> !pbcopy
nmap ,d :. !pbcopy
vmap ,y :'<, '>w !pbcopy
nmap ,y :.w !pbcopy
nmap ,p :set paste:r !pbpaste:set nopaste
nmap , :execute "tabnew ".g:help_vim_file
nmap ,h :execute "tabnew ".g:help_vim_file
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <F11> :call conque_term#exec_file()
nnoremap <silent> <Plug>Colorizer :ColorToggle
nmap <F2> :call CreateSergeHeader()
nmap <F1> :Stdheader
nmap <S-Down> :+5
nmap <S-Up> :-5
nmap <S-Left> <Left><Left><Left><Left><Left>
nmap <S-Right> <Right><Right><Right><Right><Right>
nmap <F4> :set invcursorline
nmap <F3> :set invrelativenumber
nmap <F5> :wa:mksession!
imap {{ {}<Up>
abbr testt //<d0><Left><Left><Del><Del>#include <stdio.h>#include <stdlib.h>#include <unistd.h>#include <limits.h>#include <string.h>#include <ctype.h>int				main(int ac, char **av){int			i;(void)ac;(void)av;(void)i;	return (0);}//</d0>18=<Up>15<Down>i
abbr mainn int				main(int ac, char **av){return(0);}4=<Up>2<Down>i
let &cpo=s:cpo_save
unlet s:cpo_save
set autowrite
set background=dark
set backspace=indent,eol,start
set cindent
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set hidden
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set modelines=1
set mouse=a
set omnifunc=syntaxcomplete#Complete
set runtimepath=~/.vim,~/.vim/bundle/Vundle.vim,~/.vim/bundle/lightline.vim,~/.vim/bundle/nerdtree,~/.vim/bundle/colorizer,~/.vim/bundle/syntastic,~/.vim/bundle/conque.vim,/usr/share/vim/vimfiles,/usr/share/vim/vim74,/usr/share/vim/vimfiles/after,~/.vim/after,~/.vim/bundle/Vundle.vim,~/.vim/bundle/Vundle.vim/after,~/.vim/bundle/lightline.vim/after,~/.vim/bundle/nerdtree/after,~/.vim/bundle/colorizer/after,~/.vim/bundle/syntastic/after,~/.vim/bundle/conque.vim/after
set scrolloff=4
set shiftwidth=4
set shortmess=a
set showcmd
set showmatch
set smartcase
set smartindent
set tabline=%!lightline#tabline()
set tabstop=4
set window=0
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/42projects/3_fillit/github
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +0 errorhashtag.c
argglobal
silent! argdel *
argadd errorhashtag.c
edit errorhashtag.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
argglobal
setlocal noautoindent
setlocal backupcopy=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
set colorcolumn=81
setlocal colorcolumn=81
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=0
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal lispwords=
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal modeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal smartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=%{lightline#link()}%#LightlineLeft_active_0#%(\ %{lightline#mode()}\ %)%{(&paste)?\"|\":\"\"}%(\ %{&paste?\"PASTE\":\"\"}\ %)%#LightlineLeft_active_0_1#%#LightlineLeft_active_1#%(\ %R\ %)%{(&readonly)&&(1||(&modified||!&modifiable))?\"|\":\"\"}%(\ %t\ %)%{(&modified||!&modifiable)?\"|\":\"\"}%(\ %M\ %)%#LightlineLeft_active_1_2#%#LightlineMiddle_active#%=%#LightlineRight_active_2_3#%#LightlineRight_active_2#%(\ %{&ff}\ %)%{1||1?\"|\":\"\"}%(\ %{&fenc!=#\"\"?&fenc:&enc}\ %)%{1?\"|\":\"\"}%(\ %{&ft!=#\"\"?&ft:\"no\ ft\"}\ %)%#LightlineRight_active_1_2#%#LightlineRight_active_1#%(\ %3p%%\ %)%#LightlineRight_active_0_1#%#LightlineRight_active_0#%(\ %3l:%-2v\ %)
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=4
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal undolevels=-123456
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 36) / 73)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=a
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
