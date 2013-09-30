\LoadClass{beamer}
\usetheme{default}
%\usetheme[height=25mm]{Rochester}
\usecolortheme[RGB={90,90,90}]{structure} 
\useoutertheme{infolines} 

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{hswbeamer}[2013/08/20 Custom class for Presentatins]

\RequirePackage{fixltx2e}			% fix latex
\RequirePackage[utf8]{inputenc}		% inputencryption
\RequirePackage[T1]{fontenc}		% fontencryption
%\RequirePackage[ngerman]{babel}		% language package
\RequirePackage[english]{babel}		% language package
\RequirePackage[numbers]{natbib}	% bibliography

\RequirePackage{amsmath}			% math symbols etc
\RequirePackage{amssymb}			% math symbols

\RequirePackage{makeidx}			% index generation
\RequirePackage[intoc]{nomencl}		% nomenclature settings

\RequirePackage{setspace}			% Linespacing
\RequirePackage{float}				% floating objects
\RequirePackage{caption}			% caption inside multifloat
\RequirePackage{graphicx}			% image support (float)
\RequirePackage{atbegshi}
\RequirePackage{listings}			% display sourcecode

\RequirePackage{multicol}			% paragraph columns
\RequirePackage{lipsum}				% generate lipsum
\RequirePackage{cclicenses}			% CC-Icons

\RequirePackage{xcolor}				% use colors

\RequirePackage{algorithm}
\RequirePackage{algpseudocode}

\RequirePackage{lmodern}			% something about font etc...
\RequirePackage{libertine}			% use Libertine fontset
\RequirePackage{eurosym}			% official EUR-Symbol

\RequirePackage{geometry}
\RequirePackage{hyperref}


\geometry{left=1cm, right=1cm}
\hypersetup{colorlinks=true}

%
% CONFIG
%
\addto\captionsngerman{\renewcommand{\figurename}{Abb.}} % change figure text
\addto\captionsngerman{\renewcommand{\tablename}{Tab.}}  % change figure text
\renewcommand{\nomname}{Nomenklatur}
\setlength{\nomlabelwidth}{.25\hsize}
\renewcommand{\nomlabel}[1]{#1 \dotfill}
\setlength{\nomitemsep}{-\parsep}
\providecommand{\printnomenclature}{\printglossary}
\providecommand{\makenomenclature}{\makeglossary}


\definecolor{lgray}{rgb}{0.95,0.95,0.95}
\definecolor{dgreen}{rgb}{0.0,0.3,0.0}
\definecolor{dblue}{rgb}{0.0,0.0,0.3}

\lstset{
	backgroundcolor={\color{lgray}},   
	breakatwhitespace=false,
	showspaces=false,
	showstringspaces=false, 
	basicstyle={\footnotesize\ttfamily\color{black}},                          
	commentstyle={\footnotesize\ttfamily\color{darkgray}},                              
	keywordstyle={\footnotesize\ttfamily\color{dblue}},       
	numberstyle={\footnotesize\ttfamily\color{black}},       
	stringstyle={\footnotesize\ttfamily\color{dgreen}},  
	title={Src: \lstname},                  
	breaklines={true}, 
	captionpos={b}, 
	frame={l},
	numbers=left,       
  	stepnumber=1,                   
  	numbersep=10pt,
  	tabsize=2,
  	xleftmargin=2em
}

\newcounter{RomanPages} 

%
% COMMANDS
%
\providecommand{\Rule}[1][1]{\centerline{\rule[0mm]{#1\columnwidth}{1pt}}}
\providecommand{\Cite}[3]{\footnote{\citealp[#1][#3]{#2}}}
\providecommand{\Code}[3]{\lstinputlisting[language=C, caption=#2, label={src:#3}]{#1}}
\providecommand{\Item}[2]{\item{\textbf{#1:~}#2}}

\providecommand{\Image}[5][0.9]{
	\begin{figure}[tbp]	
	\begin{center}
	\includegraphics[width=#1\textwidth]{#2}
	\caption{#3}
	\small{#4}
	\label{#5}
	\end{center}
	\end{figure}
}

\providecommand{\FrontMatter}{
	\clearpage
	\singlespacing
	\pagenumbering{roman}
	\setcounter{RomanPages}{1} 
}

\providecommand{\MainMatter}{
	\setcounter{RomanPages}{\value{page}}
	\clearpage
	\onehalfspacing
	\pagenumbering{arabic}
}

\providecommand{\SectionFrame}[1]{
    \frame{
        \begin{center}
        \vfill\huge{#1}\vfill
        \end{center}
    }
}

\providecommand{\BackMatter}{
	\clearpage
	\singlespacing
	\pagenumbering{roman}
	\setcounter{page}{\value{RomanPages}+1}
}

\algrenewtext{Function}[2]{\algorithmicfunction\ \texttt{#1}( #2 ):}
\algrenewtext{Procedure}[2]{\algorithmicprocedure\ \texttt{#1}( #2 ):}

%
% ADDITIONAL UNITS AND SYMBOLS
%
\providecommand{\Registered}[1]{#1\;\textsuperscript{\textregistered}}
\providecommand{\Trademark}[1]{#1\;\textsuperscript{\texttrademark}}
\providecommand{\Copyright}[1]{{\textcopyright\;#1}}
\providecommand{\Copyleft}[1]{{\textcopyleft\;#1}}
\providecommand{\Euro}[1]{\EUR{#1}}
\providecommand{\Celsius}[1]{$#1\;^\circ\text{C}$}
\providecommand{\Ohm}[1]{$#1\;\Omega$}