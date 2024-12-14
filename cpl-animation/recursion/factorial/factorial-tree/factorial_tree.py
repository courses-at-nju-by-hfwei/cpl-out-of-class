from manim import *

class FactorialRecursion(Scene):
    def construct(self):
        # Title
        title = Text("Recursion and Backtracking: factorial(4)", font_size=36)
        self.play(Write(title))
        self.wait(2)
        self.play(FadeOut(title))

        # Initial introduction
        intro = Text("We will compute factorial(4) step by step using recursion.", font_size=24)
        self.play(Write(intro))
        self.wait(2)
        self.play(FadeOut(intro))

        # Recursion Tree Layout
        tree = VGroup()

        # Add nodes to the tree
        node_positions = {
            "factorial(4)": (0, 3, 0),
            "factorial(3)": (-2, 1, 0),
            "factorial(2)": (-4, -1, 0),
            "factorial(1)": (-6, -3, 0),
            "factorial(0)": (-8, -5, 0)
        }

        nodes = {name: Circle(radius=0.5).set_fill(WHITE, opacity=0.5).move_to(pos) for name, pos in node_positions.items()}
        labels = {name: Text(name, font_size=24).move_to(pos) for name, pos in node_positions.items()}

        # Lines representing function calls
        lines = [
            Line(nodes["factorial(4)"].get_bottom(), nodes["factorial(3)"].get_top()),
            Line(nodes["factorial(3)"].get_bottom(), nodes["factorial(2)"].get_top()),
            Line(nodes["factorial(2)"].get_bottom(), nodes["factorial(1)"].get_top()),
            Line(nodes["factorial(1)"].get_bottom(), nodes["factorial(0)"].get_top()),
        ]

        # Add nodes and labels to the tree group
        for name in node_positions.keys():
            tree.add(nodes[name], labels[name])
        tree.add(*lines)

        # Display the tree
        self.play(Create(tree), run_time=4)
        self.wait(2)

        # Highlight recursion steps
        steps = [
            "factorial(4) = 4 * factorial(3)",
            "factorial(3) = 3 * factorial(2)",
            "factorial(2) = 2 * factorial(1)",
            "factorial(1) = 1 * factorial(0)",
            "factorial(0) = 1 (base case)"
        ]

        explanations = VGroup(*[Text(step, font_size=24).to_edge(DOWN) for step in steps])

        for i, step in enumerate(steps):
            # Highlight node
            self.play(nodes[list(node_positions.keys())[i]].animate.set_fill(YELLOW, opacity=0.8))
            self.play(Write(explanations[i]))
            self.wait(2)
            self.play(FadeOut(explanations[i]))

        # Highlight backtracking
        backtrack_values = [
            "factorial(0) = 1",
            "factorial(1) = 1 * 1 = 1",
            "factorial(2) = 2 * 1 = 2",
            "factorial(3) = 3 * 2 = 6",
            "factorial(4) = 4 * 6 = 24"
        ]

        backtrack_explanations = VGroup(*[Text(val, font_size=24).to_edge(DOWN) for val in backtrack_values])

        for i, val in enumerate(reversed(backtrack_values)):
            index = len(backtrack_values) - 1 - i
            self.play(nodes[list(node_positions.keys())[index]].animate.set_fill(GREEN, opacity=0.8))
            self.play(Write(backtrack_explanations[index]))
            self.wait(2)
            self.play(FadeOut(backtrack_explanations[index]))

        # Final result
        result = Text("factorial(4) = 24", font_size=32).to_edge(DOWN)
        self.play(Write(result))
        self.wait(3)

        self.play(FadeOut(result), FadeOut(tree))
        outro = Text("Recursion and backtracking complete!", font_size=24)
        self.play(Write(outro))
        self.wait(2)