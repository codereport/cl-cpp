import graphviz as gv

combinators = { 
    'S'  : [],
    'K'  : [],
    'I'  : ['S', 'K'],
    'κ'  : ['I', 'K'],
    'W'  : ['S', 'κ'],
    'B'  : ['S', 'K'], 
    'D'  : ['B'],
    'Φ'  : ['B₁', 'S', 'B'],
    'B₁' : ['D', 'B'],
    'C'  : ['B', 'Φ', 'S', 'K'],
    'B₂' : ['D', 'B₁'],
    'B₃' : ['B', 'D'],
    'Ψ'  : ['B', 'S', 'Φ', 'C'], 
    'D₁' : ['B', 'D']
}

dot = gv.Digraph('combinator-graph', format = 'png')

for combinator in combinators.keys():
    dot.node(combinator)

for combinator, deps in combinators.items():
    for dep in deps:
        dot.edge(dep, combinator)

dot.render(directory='.')
