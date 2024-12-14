from manim import *

class StringCopyVisualization(Scene):
    def construct(self):
        # Title
        title = Text("String Copy: while ((*dest++ = *src++) != '\\0');").scale(0.7)
        self.play(Write(title))
        self.wait(2)
        self.play(title.animate.to_edge(UP))

        # Create arrays for src and dest
        src_text = Text("src", font_size=40).to_edge(LEFT).shift(UP)
        dest_text = Text("dest", font_size=40).to_edge(LEFT).shift(DOWN)

        src_array = VGroup(*[Square().set_fill(WHITE, opacity=0.3) for _ in range(6)])
        src_chars = VGroup(*[Text(c, font_size=30) for c in "hello\0"])
        for i, (box, char) in enumerate(zip(src_array, src_chars)):
            box.next_to(src_text, RIGHT, buff=0.2 + i * 0.6)
            char.move_to(box)

        dest_array = VGroup(*[Square().set_fill(WHITE, opacity=0.3) for _ in range(6)])
        dest_chars = VGroup(*[Text("", font_size=30) for _ in range(6)])
        for i, (box, char) in enumerate(zip(dest_array, dest_chars)):
            box.next_to(dest_text, RIGHT, buff=0.2 + i * 0.6)
            char.move_to(box)

        self.play(
            Write(src_text), Write(dest_text),
            Create(src_array), Create(dest_array),
            Write(src_chars)
        )
        self.wait()

        # Pointer visualization
        src_pointer = Arrow(UP, DOWN, buff=0.1).next_to(src_array[0], UP)
        dest_pointer = Arrow(DOWN, UP, buff=0.1).next_to(dest_array[0], DOWN)

        self.play(FadeIn(src_pointer), FadeIn(dest_pointer))
        self.wait()

        # Step-by-step copying process
        for i in range(6):  # includes the null character
            # Highlight current source and destination
            self.play(
                Indicate(src_array[i], color=YELLOW),
                Indicate(dest_array[i], color=YELLOW)
            )

            # Copy character from src to dest
            self.play(Transform(dest_chars[i], Text(src_chars[i].text, font_size=30).move_to(dest_chars[i].get_center())))

            # Move pointers
            if i < 5:  # Avoid moving after the last null copy
                self.play(
                    src_pointer.animate.next_to(src_array[i + 1], UP),
                    dest_pointer.animate.next_to(dest_array[i + 1], DOWN)
                )
            self.wait()

        # Show conclusion
        conclusion = Text("Copy complete! Null character '\\0' copied.", font_size=30).next_to(dest_text, DOWN)
        self.play(Write(conclusion))
        self.wait(2)
