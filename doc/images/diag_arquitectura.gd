Storage 
{
	{ Format 1.33 }
	{ GeneratedFrom TGD-version-2.20 }
	{ WrittenBy adrian }
	{ WrittenOn "" }
}

Document 
{
	{ Type "Generic Diagram" }
	{ Name diag_arquitectura.gd }
	{ Author adrian }
	{ CreatedOn "" }
	{ Annotation "" }
	{ Hierarchy False }
}

Page 
{
	{ PageOrientation Portrait }
	{ PageSize A4 }
	{ ShowHeaders False }
	{ ShowFooters False }
	{ ShowNumbers False }
}

Scale 
{
	{ ScaleValue 1 }
}

# GRAPH NODES

GenericNode 1
{
	{ Name "MSC" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 2
{
	{ Name "AST" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 3
{
	{ Name "lexer" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 5
{
	{ Name "Parser" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 6
{
	{ Name "Back-end" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 7
{
	{ Name "error" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 8
{
	{ Name ".tex" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 9
{
	{ Name "Analisis\rSemantico" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 20
{
	{ Name "error" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

GenericNode 21
{
	{ Name "TOKENS" }
	{ Annotation "" }
	{ Parent 0 }
	{ Index "" }
}

# GRAPH EDGES

GenericEdge 22
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 1 }
	{ Subject2 3 }
}

GenericEdge 23
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 5 }
	{ Subject2 7 }
}

GenericEdge 24
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 5 }
	{ Subject2 2 }
}

GenericEdge 25
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 2 }
	{ Subject2 9 }
}

GenericEdge 26
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 9 }
	{ Subject2 2 }
}

GenericEdge 27
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 2 }
	{ Subject2 6 }
}

GenericEdge 28
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 6 }
	{ Subject2 8 }
}

GenericEdge 29
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 2 }
	{ Subject2 20 }
}

GenericEdge 30
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 3 }
	{ Subject2 21 }
}

GenericEdge 31
{
	{ Name "" }
	{ Annotation "" }
	{ Parent 0 }
	{ Subject1 21 }
	{ Subject2 5 }
}

# VIEWS AND GRAPHICAL SHAPES

View 10
{
	{ Index "0" }
	{ Parent 0 }
}

Box 11
{
	{ View 10 }
	{ Subject 1 }
	{ Position 60 60 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Box 12
{
	{ View 10 }
	{ Subject 2 }
	{ Position 470 150 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Ellipse 13
{
	{ View 10 }
	{ Subject 3 }
	{ Position 200 60 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Ellipse 15
{
	{ View 10 }
	{ Subject 5 }
	{ Position 470 60 }
	{ Size 84 42 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Ellipse 16
{
	{ View 10 }
	{ Subject 6 }
	{ Position 330 150 }
	{ Size 105 48 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Box 17
{
	{ View 10 }
	{ Subject 7 }
	{ Position 600 60 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Box 18
{
	{ View 10 }
	{ Subject 8 }
	{ Position 200 150 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Ellipse 19
{
	{ View 10 }
	{ Subject 9 }
	{ Position 470 230 }
	{ Size 137 64 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 32
{
	{ View 10 }
	{ Subject 22 }
	{ FromShape 11 }
	{ ToShape 13 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 100 60 }
	{ Point 160 60 }
	{ NamePosition 130 50 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 33
{
	{ View 10 }
	{ Subject 23 }
	{ FromShape 15 }
	{ ToShape 17 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 512 60 }
	{ Point 560 60 }
	{ NamePosition 536 50 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 34
{
	{ View 10 }
	{ Subject 24 }
	{ FromShape 15 }
	{ ToShape 12 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 470 81 }
	{ Point 470 130 }
	{ NamePosition 456 105 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 35
{
	{ View 10 }
	{ Subject 25 }
	{ FromShape 12 }
	{ ToShape 19 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 450 170 }
	{ Point 436 202 }
	{ NamePosition 431 182 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 36
{
	{ View 10 }
	{ Subject 26 }
	{ FromShape 19 }
	{ ToShape 12 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 504 202 }
	{ Point 490 170 }
	{ NamePosition 509 182 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 37
{
	{ View 10 }
	{ Subject 27 }
	{ FromShape 12 }
	{ ToShape 16 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 430 150 }
	{ Point 383 150 }
	{ NamePosition 406 140 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 38
{
	{ View 10 }
	{ Subject 28 }
	{ FromShape 16 }
	{ ToShape 18 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 278 150 }
	{ Point 240 150 }
	{ NamePosition 259 140 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Box 39
{
	{ View 10 }
	{ Subject 20 }
	{ Position 600 150 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 40
{
	{ View 10 }
	{ Subject 29 }
	{ FromShape 12 }
	{ ToShape 39 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 510 150 }
	{ Point 560 150 }
	{ NamePosition 535 140 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Box 41
{
	{ View 10 }
	{ Subject 21 }
	{ Position 330 60 }
	{ Size 80 40 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FillStyle Unfilled }
	{ FillColor "white" }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 42
{
	{ View 10 }
	{ Subject 30 }
	{ FromShape 13 }
	{ ToShape 41 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 240 60 }
	{ Point 290 60 }
	{ NamePosition 265 50 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

Line 43
{
	{ View 10 }
	{ Subject 31 }
	{ FromShape 41 }
	{ ToShape 15 }
	{ Curved False }
	{ End1 Empty }
	{ End2 FilledArrow }
	{ Points 2 }
	{ Point 370 60 }
	{ Point 428 60 }
	{ NamePosition 399 50 }
	{ Color "black" }
	{ LineWidth 1 }
	{ LineStyle Solid }
	{ FixedName False }
	{ Font "-*-courier-medium-r-normal--14*" }
	{ TextAlignment Center }
	{ TextColor "black" }
	{ NameUnderlined False }
}

