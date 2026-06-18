let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
doautoall SessionLoadPre
silent only
silent tabonly
cd ~/Development/DSA-c
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
set shortmess+=aoO
badd +4 ~/Development/deepseek/main.py
badd +1 ~/Development/DSA-c/Binary-Search-Tree.c
badd +1 Session.vim
badd +10 recursion/factorial.c
badd +13 recursion/sum_of_digits.c
badd +16 recursion/is_palindrome.c
badd +12 recursion/fast_exponent.c
badd +12 recursion/gcd_euclidian.c
badd +14 recursion/grid_path.c
badd +11 recursion/fibonacci.c
badd +11 recursion/hanoi.c
badd +16 recursion/binary_search.c
badd +20 recursion/merge_sort.c
badd +1 recursion/stairs.c
badd +53 dijkstra.c
badd +63 temp.c
badd +1 recursion/longest_common_subsequence.c
badd +37 recursion/longest_common_subsequence_DP_bottom_up.c
badd +12 recursion/longest_common_subsequence_DP_top_down.c
badd +3 test.c
badd +21 subsets.c
argglobal
%argdel
edit recursion/longest_common_subsequence_DP_top_down.c
argglobal
balt subsets.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((14 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 023|
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
