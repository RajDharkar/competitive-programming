from manim import *

class SegTreeVisualization(Scene):
    def construct(self):
        self.intro()
        self.showarr()
        self.display_functions()
        self.update_segtree(6, 108) 
        self.wait(1.5)
        self.updsegtree(7, 7, 0.8)
        self.wait(0.75)
        self.updsegtree(8, 9, 0.7)
        self.wait(0.25)
        self.updsegtree(2, 99, 0.5)
        self.wait(0.25)
        self.updsegtree(4, 11, 0.3)
        self.wait(0.25)
        self.updsegtree(1, 5, 0.3)
        self.wait(0.25)
        self.updsegtree(3, 6, 0.3)
        self.wait(0.25)
        self.updsegtree(5, 0, 0.2)
        self.wait(0.25)
        self.updsegtree(0, 1, 0.2)
        self.wait(0.25)

    def intro(self):
        beginning_intro = Text("Sum Query Segment Tree", font_size=48)
        self.play(AddTextLetterByLetter(beginning_intro))
        self.wait(0.5)

        usage = Text("Usage", font_size=36)
        underline = Underline(usage)
        self.usage_group = VGroup(usage, underline)

        self.play(ReplacementTransform(beginning_intro, usage))
        self.play(Create(underline)) 
        self.play(self.usage_group.animate.scale(0.8).to_edge(UP))
        self.wait(0.5)

    def showarr(self):
        array_values = [4, 8, 15, 16, 23, 42, 6, 0, 10, 40, 13, 12] 
        elements = []
        indexes = []

        for idx, value in enumerate(array_values):
            square = Square(side_length=1)
            label = Text(str(value)).scale(0.7).move_to(square.get_center())
            element = VGroup(square, label)
            elements.append(element)
            index = Text(str(idx)).scale(0.5).set_color(BLUE)
            indexes.append(index)

        array_group = VGroup(*elements).arrange(buff=0)
        index_group = VGroup(*indexes)
        for idx_label, element in zip(index_group, array_group):
            idx_label.next_to(element, DOWN, buff=0.2)

        full_group = VGroup(array_group, index_group).move_to(ORIGIN)
        for element, idx_label in zip(array_group, index_group):
            self.play(FadeIn(element, run_time=0.3), FadeIn(idx_label, run_time=0.3))
        
        self.play(full_group.animate.shift(DOWN * 2.5))
        self.play(FadeOut(self.usage_group))
        self.wait(0.5)

        self.array_group = array_group
        self.index_group = index_group

    def display_functions(self):
        self.update_func = Text("update(index, value)", font_size=24).set_color(WHITE)
        self.query_func = Text("query(left, right)", font_size=24).set_color(WHITE)
        function_group = VGroup(self.update_func, self.query_func).arrange(RIGHT, buff=2)
        function_group.to_edge(UP)
        self.play(Write(function_group))
        self.wait(0.5)
    def update_segtree(self, ind, val):
        self.updsegtree(ind, val, 1)

    def updsegtree(self, ind, val, mult):
        call_str = f"update({ind}, {val})"
        t2c = {str(ind): BLUE, str(val): PURE_GREEN}
        call = Text(call_str, font_size=28, t2c=t2c)
        
        call.next_to(self.update_func, DOWN, buff=0.3)
        self.add(call)
        self.wait(0.5*mult)

        self.play(call.animate.scale(2).move_to(ORIGIN))
        self.wait(1*mult)

        comma = call_str.index(",")
        left_paren = call_str.index("(")
        right_paren = call_str.index(")")
        # idx_part = call[left_paren+1:comma]
   
        underline_idx = Underline(VGroup(*call[left_paren+1:comma]), color=BLUE)
        # self.play(Create(underline))
        # self.wait()

        self.play(Create(underline_idx), run_time=0.4*mult)
        self.wait(0.5*mult)

        index_label = self.index_group[ind]
        circle = Circle(radius=0.2, color=BLUE).move_to(index_label)
        self.play(Create(circle), run_time=0.4*mult)
        self.wait(0.5*mult)

        # val_part = call[comma+1:right_paren]
        underline_val = Underline(VGroup(*call[comma+1:right_paren-1]), color=PURE_GREEN)
        self.play(Create(underline_val), run_time=0.4*mult)
        self.wait(0.5*mult)

        cell = self.array_group[ind]
        highlight = SurroundingRectangle(cell, buff=0.05, color=PURE_GREEN)
        self.play(Create(highlight), run_time=0.4*mult)
        self.wait(0.5*mult)

        square, label = cell
        new_label = Text(str(val), font_size=24).move_to(label.get_center())
        self.play(Transform(label, new_label), run_time=0.5*mult)
        self.wait(0.5*mult)

        self.play(
            Uncreate(underline_idx),
            Uncreate(underline_val),
            Uncreate(circle),
            Uncreate(highlight),
            FadeOut(call),
            run_time=0.75*mult
        )
