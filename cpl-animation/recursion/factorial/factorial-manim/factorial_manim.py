from manim import *

class RecursionVisualization(Scene):
    def construct(self):
        # Title of the scene
        title = Text("Visualizing Recursion: Factorial").scale(0.8).to_edge(UP)
        self.play(Write(title))

        # Factorial formula
        formula = MathTex("n!", "=", "n", "\\times", "(n-1)!").scale(0.9).next_to(title, DOWN)
        self.play(Write(formula))
        self.wait(1)

        # Example breakdown of factorial (5!)
        example = Text("Example: 5!").scale(0.8).next_to(formula, DOWN)
        self.play(Write(example))
        self.wait(1)

        # Break down 5! recursively
        steps = [
            MathTex("5!", "=", "5", "\\times", "4!"),
            MathTex("4!", "=", "4", "\\times", "3!"),
            MathTex("3!", "=", "3", "\\times", "2!"),
            MathTex("2!", "=", "2", "\\times", "1!"),
            MathTex("1!", "=", "1"),
        ]

        # Animate recursive breakdown
        step_group = VGroup(*[step.scale(0.8) for step in steps]).arrange(DOWN, buff=0.5).to_edge(LEFT)
        for i, step in enumerate(steps):
            self.play(Write(step))
            self.wait(1)

        # Final evaluation: 5! = 120
        result = MathTex("5!", "=", "120").scale(0.9).to_edge(DOWN)
        self.play(Write(result))
        self.wait(2)

        # Show recursive stack visualization
        stack_title = Text("Recursive Stack").scale(0.8).to_edge(RIGHT + UP)
        self.play(Write(stack_title))

        # Stack elements
        stack_elements = [
            Text("factorial(5)").scale(0.7),
            Text("factorial(4)").scale(0.7),
            Text("factorial(3)").scale(0.7),
            Text("factorial(2)").scale(0.7),
            Text("factorial(1)").scale(0.7),
        ]
        stack = VGroup(*stack_elements).arrange(DOWN, buff=0.3).to_edge(RIGHT)

        for element in stack_elements:
            self.play(FadeIn(element))
            self.wait(0.5)

        # Animate the stack unwinding
        for element in reversed(stack_elements):
            self.play(FadeOut(element))
            self.wait(0.5)

        self.wait(2)