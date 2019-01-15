$('ul').on('click','span',function(event){
  $(this).parent().fadeOut(700,function(){
    $(this).remove();
  });
})

$("input").keypress(function(enter_key){
  if(enter_key.which === 13){
    var text = $(this).val();
    $(this).val("");
    $('ul').append("<li><span><i class='fas fa-trash-alt'></i> </span> "+text+"</li>");
  }
})
