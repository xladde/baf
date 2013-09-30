\LoadClass[a4paper, 10pt]{article}
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{hswpaper.cls}[2013/08/22 Custom class for simple HSW-Papers]

\RequirePackage[ngerman]{babel}
\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{amsmath}
\RequirePackage{amssymb}
\RequirePackage{graphicx}
\RequirePackage{listings}
\RequirePackage{algorithm}
\RequirePackage{algpseudocode}
\RequirePackage{textcomp}
\RequirePackage[numbers]{natbib}
\RequirePackage{cclicenses}
\RequirePackage{caption}
\RequirePackage{lipsum}
\RequirePackage{indentfirst}
\RequirePackage{makeidx}			% index generation
\RequirePackage[intoc]{nomencl}		% nomenclature settings
\RequirePackage[colorlinks=true, linkcolor=black, urlcolor=black]{hyperref}

%
% CONFIGURATION
%
\renewcommand\theparagraph{\roman{paragraph}}
\renewcommand\thesubparagraph{\theparagraph.\alph{subparagraph})}


\setcounter{secnumdepth}{5}

\addto\captionsngerman{\renewcommand{\figurename}{Abb.}}
\addto\captionsngerman{\renewcommand{\tablename}{Tab.}}

\renewcommand{\nomname}{Nomenklatur}
\setlength{\nomlabelwidth}{.25\hsize}
\renewcommand{\nomlabel}[1]{#1 \dotfill}
\setlength{\nomitemsep}{-\parsep}
\providecommand{\printnomenclature}{\printglossary}
\providecommand{\makenomenclature}{\makeglossary}


\algrenewtext{Function}[2]{\algorithmicfunction\ \texttt{#1}( #2 ):}
\algrenewtext{Procedure}[2]{\algorithmicprocedure\ \texttt{#1}( #2 ):}

\bibliographystyle{natdin}

\lstset{
	title={\lstname}, 
    breakatwhitespace=false,
	showspaces=false,
	showstringspaces=false, 
	basicstyle={\small\ttfamily},                          
	commentstyle={\small\ttfamily},                              
	keywordstyle={\small\ttfamily},       
	numberstyle={\small\ttfamily},       
	stringstyle={\small\ttfamily},                   
	breaklines={true}, 
	captionpos={b}, 
	numbers=left,       
  	stepnumber=1,                   
  	numbersep=2em,
  	tabsize=2,
  	xleftmargin=3em
}

%
% ADDITIONAL UNITS AND SYMBOLS
%
\providecommand{\Rule}[1][1]{\centerline{\rule[0mm]{#1\columnwidth}{1pt}}}
\providecommand{\Registered}[1]{#1\;\textsuperscript{\textregistered}}
\providecommand{\Trademark}[1]{#1\;\textsuperscript{\texttrademark}}
\providecommand{\Copyright}[1]{{\textcopyright\;#1}}
\providecommand{\Copyleft}[1]{{\textcopyleft\;#1}}
\providecommand{\Euro}[1]{\EUR{#1}}
\providecommand{\Celsius}[1]{$#1\;^\circ\text{C}$}
\providecommand{\Ohm}[1]{$#1\;\Omega$}

\algblockdefx[StructureBlock]{Structure}{EndStructure}%
    [1]{\textbf{structure} \textsc{#1}\textbf{:}}%
    {\textbf{end structure;}}
\algblockdefx[ClassBlock]{Class}{EndClass}%
    [1]{\textbf{class} \textsc{#1}\textbf{:}}%
    {\textbf{end class;}}
    

\makeindex
\makenomenclature