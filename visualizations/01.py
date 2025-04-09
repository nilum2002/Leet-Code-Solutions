from manim import *

class RemoveNthFromEnd(Scene):
    def construct(self):
        # Create linked list nodes visually: dummy(0) -> 1 -> 2 -> 3 -> 4 -> 5
        dummy = Circle(radius=0.4, color=GRAY).shift(LEFT * 1.5)
        dummy_label = Text("0", font_size=24).move_to(dummy)
        
        nodes = [Circle(radius=0.4, color=BLUE).shift(RIGHT * i) for i in range(5)]
        labels = [Text(str(i+1), font_size=24).move_to(nodes[i]) for i in range(5)]
        
        # Create arrows between dummy -> nodes
        arrows = [Arrow(dummy.get_right(), nodes[0].get_left(), buff=0.05)]
        arrows += [Arrow(nodes[i].get_right(), nodes[i+1].get_left(), buff=0.05) for i in range(4)]

        # Draw dummy
        self.play(Create(dummy), Write(dummy_label))
        
        # Draw all nodes and labels
        for node, label in zip(nodes, labels):
            self.play(Create(node), Write(label))
        for arrow in arrows:
            self.play(Create(arrow), run_time=0.2)

        self.wait(1)

        # Move A pointer n times ahead (n = 2 here)
        A_pointer = Text("A", font_size=24, color=BLUE).next_to(dummy, UP)
        B_pointer = Text("B", font_size=24, color=GREEN).next_to(dummy, DOWN)
        self.play(Write(A_pointer), Write(B_pointer))
        self.wait(1)

        # Move A 2 steps forward (n=2), to node 2 (index 1)
        for i in range(2):
            self.play(A_pointer.animate.next_to(nodes[i], UP), run_time=0.5)
        self.wait(1)

        # Move A and B together until A reaches node 5
        for i in range(2, 4):
            self.play(A_pointer.animate.next_to(nodes[i], UP), B_pointer.animate.next_to(nodes[i-1], DOWN), run_time=0.5)
        self.wait(1)

        # Simulate deletion of node 4 (B->next)
        to_be_deleted = nodes[3]
        self.play(FadeOut(arrows[3]), run_time=0.3)  # Remove arrow to node 4
        new_arrow = Arrow(nodes[2].get_right(), nodes[4].get_left(), buff=0.05, color=RED)
        self.play(Create(new_arrow), run_time=0.5)

        # Cross out deleted node
        cross = Cross(to_be_deleted, stroke_color=RED)
        self.play(Create(cross))
        self.wait(2)
