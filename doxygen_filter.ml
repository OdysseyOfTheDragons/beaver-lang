let filter_math str =
    let r = Str.regexp "\\$\\([^$ ]\\|[^ ]*[^$ ]\\)\\$" in
    Str.global_replace r {|\f$\1\f$|} str

let filter_first_blank_line str =
    let r = Str.regexp
        "\\(\\*\\*[^*]*\\*+\\(\\([^*/]\\|\\*+[^/*]\\)*\\)\\*+/\\)\n" in
    try
        let _ = Str.search_forward r str 0 in
        let comment = Str.matched_group 1 str in
        let start = Str.match_beginning () in
        if start < 2 then (* this may be 0 or 1 *)
            Str.replace_first r comment str
        else
            raise Not_found
    with Not_found -> str

let filter filename =
    let file = open_in_bin filename in
    let content = really_input_string file (in_channel_length file) in
    let transformed =
        content |> filter_math (*|> filter_first_blank_line*) in
    print_endline transformed

let main () =
    filter Sys.argv.(1)

let () = main ()
